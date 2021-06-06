import os
import sys
import pyparsing
import subprocess

sys.setrecursionlimit(5000)
pyparsing.ParserElement.enablePackrat()


def infix_to_prefix(input_string):
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

    class OperatorHandler(Handler):
        def prefix(self):
            lhs = self.tokens[:-2]
            op = self.tokens[-2]
            rhs = self.tokens[-1]
            if len(lhs) == 1:
                return "({} {} {})".format(op, lhs[0].prefix(), rhs.prefix())
            return "({} {} {})".format(op, OperatorHandler([lhs]).prefix(), rhs.prefix())

    real = pyparsing.Combine(pyparsing.Word(pyparsing.nums) + "." + pyparsing.Word(pyparsing.nums))
    integer = pyparsing.Word(pyparsing.nums)

    variable = pyparsing.Combine(pyparsing.Word(pyparsing.alphas) + pyparsing.Optional(pyparsing.Word(pyparsing.alphanums)))
    variable.setParseAction(VariableHandler)

    number = real | integer
    number.setParseAction(NumberHandler)

    operand = number | variable

    plus_minus = pyparsing.oneOf("+ -")
    times_divide = pyparsing.oneOf("* /")

    expr = pyparsing.infixNotation(
        operand,
        [
            (times_divide, 2, pyparsing.opAssoc.LEFT, OperatorHandler),
            (plus_minus, 2, pyparsing.opAssoc.LEFT, OperatorHandler),
        ]
    )

    return (expr.parseString(input_string)[0].prefix(),
            VariableHandler.variable_map,
            VariableHandler.reverse_variable_map)


def prefix_to_infix(input_string, variable_map):
    func_name = pyparsing.oneOf("+ - / *")
    real = pyparsing.Combine(pyparsing.Word(pyparsing.nums) + "." + pyparsing.Word(pyparsing.nums))
    integer = pyparsing.Word(pyparsing.nums)
    variable = pyparsing.Combine("x" + pyparsing.Word(pyparsing.nums))

    expression = pyparsing.Forward()
    expression << pyparsing.Suppress("(") + pyparsing.Group(func_name + pyparsing.OneOrMore(expression | real | integer | variable)) + pyparsing.Suppress(")")

    def build_infix(root):
        if not isinstance(root, list):
            if isinstance(root, str) and root.startswith("x"):
                return variable_map[root]
            return root
        return "({}) {} ({})".format(build_infix(root[1]), root[0], build_infix(root[2]))

    res = expression.parseString(input_string)
    return build_infix(res[0].asList())


variable_maps = []

p = subprocess.Popen(["./clang_ast_visitor", sys.argv[1]], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
clang_stdout, _ = p.communicate()
clang_stdout = clang_stdout.decode("utf8")

with open("herbie.txt") as inp:
    with open("expr_prefix.txt", "w") as out:
        for line in inp:
            res, var_map, reverse_var_map = infix_to_prefix(line)
            variable_maps.append(reverse_var_map)
            out.write("(FPCore ({}) :precision binary64 {})\n".format(" ".join(var_map.values()), res))

os.system("herbie improve expr_prefix.txt out.txt")

i = 0
with open("out.txt") as herbie_raw:
    for line in herbie_raw:
        if not line.startswith("(FPCore"):
            continue
        line = line.split(":precision binary64")[1][:-2].strip()
        infix_line = prefix_to_infix(line, variable_maps[i])
        clang_stdout = clang_stdout.replace(r'"<{[HERBIE-' + str(i) + r']}>"', infix_line)
        i += 1

with open("{}.herbie".format(sys.argv[1]), "w") as out:
    out.write(clang_stdout)

