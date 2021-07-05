import os
import sys
import random
import subprocess

if sys.argv[1] == "-c":
    os.system("bash prepare_template.sh tests/{}.cpp".format(os.path.basename(__file__)[:-3]))

digits = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]


def random_double(wl, wu, dp):
    res = str(random.randint(wl, wu))
    res += "."
    for _ in range(dp):
        res += random.choice(digits)
    return res


def random_sci_double(wl, wu, dp, el, eu):
    res = str(random.randint(wl, wu))
    res += "."
    for _ in range(dp):
        res += random.choice(digits)
    res += "e" + str(random.randint(el, eu))
    return res


def run_process(args, type, with_herbie=True):
    p = subprocess.Popen(["/tmp/igen_{}{}".format("herbie_" if with_herbie else "", type)] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = p.communicate()
    print(stdout.decode("utf8"), end="")


for i in range(100):
    if sys.argv[2] == "s":
        a = random_double(-10, 10, 3)
        b = random_double(-1000, 1000, 3)
        c = random_double(-10, 10, 3)
    elif sys.argv[2] == "m":
        a = random_sci_double(-10, 10, 3, 5, 10)
        b = random_sci_double(-10, 10, 3, 20, 40)
        c = random_sci_double(-10, 10, 3, 5, 10)
    elif sys.argv[2] == "l":
        a = random_sci_double(-10, 10, 3, 20, 40)
        b = random_sci_double(-10, 10, 3, 100, 120)
        c = random_sci_double(-10, 10, 3, 20, 40)
    else:
        raise
    args = [a, a, b, b, c, c]
    run_process(args, "accuracy")
    run_process(args, "accuracy", False)
    run_process(args, "runtime")
    run_process(args, "runtime", False)
