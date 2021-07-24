import os
import random
import sys
import pyparsing
import subprocess

from herbie_utils import infix_to_ast, prefix_to_ast
from ast_opt import simplify

sys.setrecursionlimit(5000)
pyparsing.ParserElement.enablePackrat()

ORIG_EXPRESSIONS = "herbie_vals.txt"
ORIG_EXPRESSIONS_PREFIX = "herbie_vals_prefix.txt"
HERBIED_EXPRESSIONS_PREFIX = "herbie_vals_out_prefix.txt"
IR_SOURCE = "herbie_ir.txt"

HERBIE_OPTS = "--disable generate:taylor"
# HERBIE_OPTS = ""


# extract seed
herbie_seed = int(sys.argv[1])
argv = sys.argv[2:]

# run the compiler
print("running {}".format(argv))
p = subprocess.Popen(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
stdout, stderr = p.communicate()
print(stdout.decode("utf8"))
print(stderr.decode("utf8"))


variable_maps = []

# convert expressions to prefix form
with open(ORIG_EXPRESSIONS) as inp:
    with open(ORIG_EXPRESSIONS_PREFIX, "w") as out:
        for line in inp:
            res, var_map, reverse_var_map = infix_to_ast(line)
            variable_maps.append(reverse_var_map)
            out.write("(FPCore ({}) :precision binary64 {})\n".format(" ".join(var_map.values()), res.to_prefix()))


# run herbie
os.system("herbie improve --seed {} {} {} {}".format(
    herbie_seed, HERBIE_OPTS, ORIG_EXPRESSIONS_PREFIX, HERBIED_EXPRESSIONS_PREFIX))

i = 0
herbie_ir = open(IR_SOURCE).read()

with open(HERBIED_EXPRESSIONS_PREFIX) as herbie_raw:
    for line in herbie_raw:
        if not line.startswith("(FPCore"):  # filter out non-result lines from the output
            continue
        line = line.split(":precision binary64")[1][:-2].strip()
        ast = prefix_to_ast(line, variable_maps[i])
        simplify(ast)
        print("resulting line: {}".format(ast.to_infix()))
        herbie_ir = herbie_ir.replace("\"<{[HERBIE-"+ str(i+1) +"]}>\"", ast.to_infix())
        i += 1


# write results into igen prep file as well as aside to be able to retrieve the original code
with open(os.path.join(argv[1]), "w") as f:
    with open("herbie_result.txt", "w") as f2:
        f.write(herbie_ir)
        f2.write(herbie_ir)


os.remove(ORIG_EXPRESSIONS)
os.remove(ORIG_EXPRESSIONS_PREFIX)
os.remove(HERBIED_EXPRESSIONS_PREFIX)
os.remove(IR_SOURCE)
