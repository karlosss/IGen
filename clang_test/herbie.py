import os
import sys
import pyparsing
import subprocess
import math
from pathlib import Path

sys.setrecursionlimit(5000)
pyparsing.ParserElement.enablePackrat()

HERBIE_OPTS = "--seed 434743881 --disable generate:taylor"


def l(x):
    if isinstance(x, list):
        return x
    return [x]


def optimize_expr(expr):
    if expr[0] == "pow":
        if isinstance(expr[1][0], list) and expr[1][0][0] == "sqrt" and isinstance(expr[1][2], str) and expr[1][2] == "2.0":
            return expr[1][0][1]
        elif isinstance(expr[1][0], list) and expr[1][0][0] == "cbrt" and isinstance(expr[1][2], str) and expr[1][2] == "3.0":
            return expr[1][0][1]
        elif isinstance(expr[1][0], list) and expr[1][0][0] == "cbrt" and isinstance(expr[1][2], str) and expr[1][2].endswith(".0") and float(expr[1][2])/3 == float(expr[1][2])//3:
            return ["pow", [expr[1][0][1], ",", str(float(expr[1][2])//3)]]
        elif isinstance(expr[1][2], str) and expr[1][2] == "0.5":
            return ["sqrt", l(expr[1][0])]
        elif isinstance(expr[1][2], list) or (isinstance(expr[1][2], str) and "." in expr[1][2] and not expr[1][2].endswith(".0")):
            raise NotImplementedError("power to a non-integral number is not supported")

    elif expr[0] == "sqrt":
        if expr[1][0] == "pow" and isinstance(expr[1][1][2], str) and expr[1][1][2] == "2.0":
            return expr[1][1][0]

    elif expr[0] == "cbrt":
        if expr[1][0] == "pow" and isinstance(expr[1][1][2], str) and expr[1][1][2] == "3.0":
            return expr[1][1][0]
        if isinstance(expr[1][0], str) and expr[1][0] in ("1.0", "-1.0"):
            return expr[1][0]

    elif expr[0] == "exp":
        if expr[1][0] == "log":
            return expr[1][1]

    elif expr[0] == "log":
        if expr[1][0] == "exp":
            return expr[1][1]

    else:
        raise NotImplementedError("Cannot optimize {}".format(expr[0]))
    return expr


def expr_to_str(expr):
    if isinstance(expr, str):
        return expr
    res = "("
    for item in expr:
        res += expr_to_str(item)
    res += ")"
    return res


def infix_to_prefix(input_string):
    print("<infix_to_prefix> " + input_string[:-1])

    class Handler:
        def __init__(self, tokens):
            self.tokens = tokens[0]

        def prefix(self):
            raise NotImplementedError

    class VariableHandler(Handler):
        variable_map = {}
        reverse_variable_map = {}

        def prefix(self):
            if self.tokens not in self.variable_map:
                self.variable_map[self.tokens] = "x{}".format(len(self.variable_map))
            self.reverse_variable_map[self.variable_map[self.tokens]] = self.tokens
            return self.variable_map[self.tokens]

    class NumberHandler(Handler):
        def prefix(self):
            return str(self.tokens)

    class BinaryOperatorHandler(Handler):
        def prefix(self):
            lhs = self.tokens[:-2]
            op = self.tokens[-2]
            rhs = self.tokens[-1]
            if len(lhs) == 1:
                return "({} {} {})".format(op, lhs[0].prefix(), rhs.prefix())
            return "({} {} {})".format(op, BinaryOperatorHandler([lhs]).prefix(), rhs.prefix())

    class UnaryOperatorHandler(Handler):
        def prefix(self):
            return "({} {})".format(self.tokens[0], self.tokens[1].prefix())

    real = pyparsing.pyparsing_common.sci_real
    integer = pyparsing.pyparsing_common.integer
    number = real | integer
    number.setParseAction(NumberHandler)

    variable = pyparsing.Combine(pyparsing.Word(pyparsing.alphas) + pyparsing.Optional(pyparsing.Word(pyparsing.alphanums))) | pyparsing.Combine("*((" + pyparsing.CharsNotIn(")") + "))") | pyparsing.Combine("*(" + pyparsing.CharsNotIn(")") + ")")
    variable.setParseAction(VariableHandler)

    operand = number | variable

    plus_minus = pyparsing.oneOf("+ -")
    unary_plus_minus_sqrt = pyparsing.oneOf("+ - sqrt")
    times_divide = pyparsing.oneOf("* /")

    expr = pyparsing.infixNotation(
        operand,
        [
            (unary_plus_minus_sqrt, 1, pyparsing.opAssoc.RIGHT, UnaryOperatorHandler),
            (times_divide, 2, pyparsing.opAssoc.LEFT, BinaryOperatorHandler),
            (plus_minus, 2, pyparsing.opAssoc.LEFT, BinaryOperatorHandler),
        ]
    )

    return (expr.parseString(input_string)[0].prefix(),
            VariableHandler.variable_map,
            VariableHandler.reverse_variable_map)


def prefix_to_infix(input_string, variable_map):
    print("<prefix_to_infix> " + input_string, variable_map)

    func_name = pyparsing.oneOf("+ - / * sqrt cbrt pow log exp if < > <= >= == != not and or")
    real = pyparsing.pyparsing_common.sci_real
    integer = pyparsing.pyparsing_common.integer
    variable = pyparsing.Combine("x" + pyparsing.Word(pyparsing.nums))
    terminal = pyparsing.Combine(pyparsing.Optional("-") + (real | integer | variable))

    expression = pyparsing.Forward()
    expression << (terminal | (
            pyparsing.Suppress("(") +
            pyparsing.Group(func_name + pyparsing.OneOrMore(expression | terminal)) +
            pyparsing.Suppress(")")
    ))

    def build_infix(root):
        if not isinstance(root, list):
            if isinstance(root, str) and root.startswith("x"):
                return variable_map[root]
            return root
        elif len(root) == 2:
            if root[0] == "not":
                return ["!", l(build_infix(root[1]))]
            elif root[0] in ("sqrt", "cbrt", "exp", "log"):
                return optimize_expr([root[0], l(build_infix(root[1]))])
            return [build_infix(root[0]), l(build_infix(root[1]))]
        if len(root) == 3:
            if root[0] in ("*", "-", "/", "+", "<", ">", "<=", ">=", "==", "!="):
                return [build_infix(root[1]), root[0], build_infix(root[2])]
            elif root[0] == "pow":
                return optimize_expr(["pow", [build_infix(root[1]), ",", build_infix(root[2])]])
            elif root[0] == "or":
                return [build_infix(root[1]), "||", build_infix(root[2])]
            elif root[0] == "and":
                return [build_infix(root[1]), "&&", build_infix(root[2])]
            else:
                print(root)
                raise
        elif len(root) == 4:
            if root[0] == "if":
                return [build_infix(root[1]), "?", build_infix(root[2]), ":", build_infix(root[3])]
            else:
                print(root)
                raise
        else:
            print(root)
            raise

    res = expression.parseString(input_string)
    if isinstance(res[0], str):
        if res[0] in variable_map:
            return variable_map[res[0]]
        return res[0]
    expr = build_infix(res[0].asList())
    return expr_to_str(expr)


variable_maps = []

print("running {}".format(sys.argv[1:]))
p = subprocess.Popen(sys.argv[1:], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
stdout, stderr = p.communicate()
print(stdout.decode("utf8"))
print(stderr.decode("utf8"))

with open("herbie_vals.txt") as inp:
    with open("herbie_vals_prefix.txt", "w") as out:
        for line in inp:
            res, var_map, reverse_var_map = infix_to_prefix(line)
            variable_maps.append(reverse_var_map)
            out.write("(FPCore ({}) :precision binary64 {})\n".format(" ".join(var_map.values()), res))

os.system("herbie improve {} herbie_vals_prefix.txt herbie_vals_out_prefix.txt".format(HERBIE_OPTS))

i = 0
herbie_ir = open("herbie_ir.txt").read()

with open("herbie_vals_out_prefix.txt") as herbie_raw:
    for line in herbie_raw:
        if not line.startswith("(FPCore"):
            continue
        line = line.split(":precision binary64")[1][:-2].strip()
        infix_line = prefix_to_infix(line, variable_maps[i])
        print("resulting line: {}".format(infix_line))
        herbie_ir = herbie_ir.replace("\"<{[HERBIE-"+ str(i+1) +"]}>\"", infix_line)
        i += 1

with open(os.path.join(sys.argv[2]), "w") as f:
    f.write(herbie_ir)

# os.remove("herbie_ir.txt")
# os.remove("herbie_vals.txt")
# os.remove("herbie_vals_out_prefix.txt")
# os.remove("herbie_vals_prefix.txt")
