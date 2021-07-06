import os
import sys
import random
import subprocess
import math


def compile(filename):
    os.system("bash prepare_template.sh tests/{}.cpp".format(filename))

digits = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]


def random_interval(wl, wu, dp, width=0):
    res = str(random.randint(wl, wu))
    res += "."
    for _ in range(dp):
        res += random.choice(digits)
    if width == 0:
        return [res, res]
    return [res, str(float(res)*(1+width))] if not res.startswith("-") else [str(float(res)*(1+width)), res]


def random_sci_interval(wl, wu, dp, el, eu, width=0):
    res = str(random.randint(wl, wu))
    res += "."
    for _ in range(dp):
        res += random.choice(digits)
    res += "e" + str(random.randint(el, eu))
    if width == 0:
        return [res, res]
    return [res, str(float(res)*(1+width))] if not res.startswith("-") else [str(float(res)*(1+width)), res]


def run_process(args, type, with_herbie=True):
    p = subprocess.Popen(["/tmp/igen_{}{}".format("herbie_" if with_herbie else "", type)] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = p.communicate()
    if stderr:
        print(stderr)
    return stdout.decode("utf8")


def avg(l):
    s = 0
    cnt = 0
    for item in l:
        if not math.isnan(item):
            s += item
            cnt += 1
    return round(s / cnt, 4)


def med(l):
    return l[len(l)//2]
