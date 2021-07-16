import os
import sys
import pyparsing
import subprocess

from herbie_utils import infix_to_ast, prefix_to_ast
from ast_opt import simplify

sys.setrecursionlimit(5000)
pyparsing.ParserElement.enablePackrat()

HERBIE_OPTS = "--seed 367622149 --disable generate:taylor"

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
        ast = prefix_to_ast(line, variable_maps[i])
        simplify(ast)
        print("resulting line: {}".format(ast.to_infix()))
        herbie_ir = herbie_ir.replace("\"<{[HERBIE-"+ str(i+1) +"]}>\"", ast.to_infix())
        i += 1

with open(os.path.join(sys.argv[2]), "w") as f:
    f.write(herbie_ir)

# os.remove("herbie_ir.txt")
# os.remove("herbie_vals.txt")
# os.remove("herbie_vals_out_prefix.txt")
# os.remove("herbie_vals_prefix.txt")
