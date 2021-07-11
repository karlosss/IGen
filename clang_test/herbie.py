import os
import sys
import pyparsing
import subprocess

from herbie_utils import infix_to_ast, prefix_to_ast

sys.setrecursionlimit(5000)
pyparsing.ParserElement.enablePackrat()

HERBIE_OPTS = "--disable generate:taylor"


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


variable_maps = []

print("running {}".format(sys.argv[1:]))
p = subprocess.Popen(sys.argv[1:], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
stdout, stderr = p.communicate()
print(stdout.decode("utf8"))
print(stderr.decode("utf8"))

with open("herbie_vals.txt") as inp:
    with open("herbie_vals_prefix.txt", "w") as out:
        for line in inp:
            res, var_map, reverse_var_map = infix_to_ast(line)
            variable_maps.append(reverse_var_map)
            out.write("(FPCore ({}) :precision binary64 {})\n".format(" ".join(var_map.values()), res.to_prefix()))

os.system("herbie improve {} herbie_vals_prefix.txt herbie_vals_out_prefix.txt".format(HERBIE_OPTS))

i = 0
herbie_ir = open("herbie_ir.txt").read()

with open("herbie_vals_out_prefix.txt") as herbie_raw:
    for line in herbie_raw:
        if not line.startswith("(FPCore"):
            continue
        line = line.split(":precision binary64")[1][:-2].strip()
        infix_line = prefix_to_ast(line, variable_maps[i]).to_infix()
        print("resulting line: {}".format(infix_line))
        herbie_ir = herbie_ir.replace("\"<{[HERBIE-"+ str(i+1) +"]}>\"", infix_line)
        i += 1

with open(os.path.join(sys.argv[2]), "w") as f:
    f.write(herbie_ir)

# os.remove("herbie_ir.txt")
# os.remove("herbie_vals.txt")
# os.remove("herbie_vals_out_prefix.txt")
# os.remove("herbie_vals_prefix.txt")
