import os
import random
import subprocess
import argparse
import re

DEFAULT_ITERS = 100


def init():
    args = parse_arguments()
    if args.recompile_igen:
        create_fn_sources(args.seed)
    if args.recompile_templates:
        create_template_sources(args.seed)
    if args.recompile_code:
        compile_template_sources(args.seed)
    return args


def benchmark(*param_fns, iters=None):
    def parse_accuracy_output(raw):
        s = raw.split(" ")
        acc = round(float(s[-1]), 4)
        output = s[-3:-1]
        params = s[:-3]
        return acc, output, params

    args = init()
    iters = iters or DEFAULT_ITERS

    acc_no_herbie = []
    acc_herbie = []
    run_no_herbie = []
    run_herbie = []

    print("Running benchmark")

    for i in range(iters):
        par = [x for fn in param_fns for x in fn()]

        acc, out, p = parse_accuracy_output(_run_command(["bin/accuracy", *par]))
        acc_no_herbie.append(acc)
        print("no herbie {}: {} (acc {})".format(p, out, acc))

        acc, out, p = parse_accuracy_output(_run_command(["bin/accuracy_{}".format(args.seed), *par]))
        acc_herbie.append(acc)
        print("herbie {}: {} (acc {})".format(p, out, acc))

        run_no_herbie.append(int(_run_command(["bin/runtime", *par])[:-1]))
        run_herbie.append(int(_run_command(["bin/runtime_{}".format(args.seed), *par])[:-1]))

    print("No herbie accuracy:\tmin {:<15}max {:<15}avg {:<15}med {:<15}".format(*stats(acc_no_herbie)))
    print("Herbie accuracy:\tmin {:<15}max {:<15}avg {:<15}med {:<15}".format(*stats(acc_herbie)))
    print("No herbie runtime:\tmin {:<15}max {:<15}avg {:<15}med {:<15}".format(*stats(run_no_herbie)))
    print("Herbie runtime:\t\tmin {:<15}max {:<15}avg {:<15}med {:<15}".format(*stats(run_herbie)))


def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("-s",
                        dest="seed",
                        metavar="<seed>",
                        required=False,
                        help="Herbie seed to use")
    parser.add_argument("-i",
                        dest="recompile_igen",
                        default=False,
                        action="store_true",
                        help="Generate new function sources")
    parser.add_argument("-t",
                        dest="recompile_templates",
                        default=False,
                        action="store_true",
                        help="Generate new accuracy and runtime measurement")
    parser.add_argument("-c",
                        dest="recompile_code",
                        default=False,
                        action="store_true",
                        help="(Re)compile accuracy and runtime measurement with GCC")
    args = parser.parse_args()

    if args.seed is None:  # always set the seed
        args.seed = random.randint(1, 2**31-1)
        print("Seed not set, choosing a random one: {}".format(args.seed))
        args.recompile_igen = True

    if not os.path.exists("bin/{}.cpp".format(args.seed)) or not os.path.exists("bin/no_herbie.cpp"):
        args.recompile_igen = True

    if args.recompile_igen:
        args.recompile_templates = True

    if not os.path.exists("bin/accuracy_{}.cpp".format(args.seed)) or \
            not os.path.exists("bin/runtime_{}.cpp".format(args.seed)) or \
            not os.path.exists("bin/accuracy.cpp") or not os.path.exists("bin/runtime.cpp"):
        args.recompile_templates = True

    if args.recompile_templates:
        args.recompile_code = True

    if not os.path.exists("bin/accuracy_{}".format(args.seed)) or \
            not os.path.exists("bin/runtime_{}".format(args.seed)) or \
            not os.path.exists("bin/accuracy") or not os.path.exists("bin/runtime"):
        args.recompile_code = True

    return args


def create_fn_sources(seed):
    print("Generating function source with Herbie")
    _run_igen(seed, True)
    os.remove("herbie_result.txt")
    print("Generating function source without Herbie")
    _run_igen(seed, False)


def create_template_sources(seed):
    def _read_fn(filename):
        fn = ""
        with open(filename) as f:
            for line in f:
                if not line.lstrip().startswith("#"):
                    fn += line
        return fn

    def _get_fn_decl(code):
        lines = code.split("\n")
        for line in lines:
            if re.match(r'^f64_I f\(.*{.*$', line):
                return line

    def _get_num_args(fn_decl):
        return fn_decl.count("f64_I") - 1

    def _make_code(template, fn):
        return template.replace("BOUNDS_DECL", interval_bounds)\
            .replace("F64I_DECL", f64i_decls)\
            .replace("FUNCALL", funcall)\
            .replace("FUNCTION", fn)

    print("Generating accuracy and runtime sources from templates")

    accuracy_template = open("../../herbie_runner/accuracy_template.cpp").read()
    runtime_template = open("../../herbie_runner/runtime_template.cpp").read()

    herbie_fn = _read_fn("bin/{}.cpp".format(seed))
    no_herbie_fn = _read_fn("bin/no_herbie.cpp")

    interval_bounds = ""
    f64i_decls = ""
    call_args = ""
    for i in range(_get_num_args(_get_fn_decl(herbie_fn))):
        interval_bounds += "double x{i}up = std::stod(std::string(argv[{a1}]));\n" \
                           "double x{i}lo = neg(std::string(argv[{a}]));\n".format(i=i, a1=2*i+1, a=2*i+2)
        f64i_decls += "f64_I x{i} = _ia_set_f64(x{i}lo, x{i}up);\n".format(i=i)
        call_args += ", x{i}".format(i=i)
    funcall = "f(" + call_args[2:] + ");\n"

    open("bin/accuracy_{}.cpp".format(seed), "w").write(_make_code(accuracy_template, herbie_fn))
    open("bin/runtime_{}.cpp".format(seed), "w").write(_make_code(runtime_template, herbie_fn))
    open("bin/accuracy.cpp", "w").write(_make_code(accuracy_template, no_herbie_fn))
    open("bin/runtime.cpp", "w").write(_make_code(runtime_template, no_herbie_fn))


def compile_template_sources(seed):
    def _build_cmd(filename):
        return ["g++", "bin/{}.cpp".format(filename), "-fpermissive", "-g",
                "-I", "{}/../../herbie_runner/".format(os.getcwd()),
                "-I", "{}/../../igen_lib".format(os.getcwd()),
                "-lcrlibm", "-lmpfr", "-o", "bin/{}".format(filename)]

    print("Compiling sources")
    _run_command(_build_cmd("accuracy"))
    _run_command(_build_cmd("runtime"))
    _run_command(_build_cmd("accuracy_{}".format(seed)))
    _run_command(_build_cmd("runtime_{}".format(seed)))


def _run_igen(seed, with_herbie):
    if not os.path.exists("bin"):
        os.mkdir("bin")
    cmd = ["python", "../../bin/igen.py", "src.cpp", "-s", str(seed),
           "-o", "bin/{}.cpp".format(seed if with_herbie else "no_herbie")]
    if not with_herbie:
        cmd += ["-R"]
    _run_command(cmd)

    commented_lines = []
    with open("herbie_result.txt" if with_herbie else "src.cpp") as f:
        for line in f:
            commented_lines.append("// " + line)
    with open("bin/{}.cpp".format(seed if with_herbie else "no_herbie")) as f:
        contents = f.read()
    with open("bin/{}.cpp".format(seed if with_herbie else "no_herbie"), "w") as f:
        f.write("// ORIGINAL CODE:\n" + "".join(commented_lines) + "\n" + contents)


digits = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]


def random_interval(integral_lo, integral_hi, decimal_places, exclude_zero=False, perc_width=0):
    res = str(random.randint(integral_lo, integral_hi))
    # if zero should be excluded, there is no decimal places, and a 0 got picked, repeat the pick
    while decimal_places == 0 and exclude_zero and res == "0":
        res = str(random.randint(integral_lo, integral_hi))
    if decimal_places > 0:
        res += "."
    for _ in range(decimal_places):
        res += random.choice(digits)
    # if zero should be excluded and the number is zero, append a 1 to its decimal part
    if exclude_zero and decimal_places > 0 and float(res) == 0:
        res += "1"
    if perc_width == 0:
        return [res, res]
    return [res, str(float(res)*(1+perc_width))] if not res.startswith("-") else [str(float(res)*(1+perc_width)), res]


def random_sci_interval(integral_lo, integral_hi, decimal_places, exp_lo, exp_hi, exclude_zero=False, perc_width=0):
    res = str(random.randint(integral_lo, integral_hi))
    # if zero should be excluded, there is no decimal places, and a 0 got picked, repeat the pick
    while decimal_places == 0 and exclude_zero and res == "0":
        res = str(random.randint(integral_lo, integral_hi))
    if decimal_places > 0:
        res += "."
    for _ in range(decimal_places):
        res += random.choice(digits)
    # if zero should be excluded and the number is zero, append a 1 to its decimal part
    if exclude_zero and decimal_places > 0 and float(res) == 0:
        res += "1"
    res += "e" + str(random.randint(exp_lo, exp_hi))
    if perc_width == 0:
        return [res, res]
    return [res, str(float(res)*(1+perc_width))] if not res.startswith("-") else [str(float(res)*(1+perc_width)), res]


def _run_command(cmd):
    # print("Running command: {}".format(" ".join(cmd)))
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = p.communicate()
    if stderr:
        print(stderr.decode("utf8"))
    return stdout.decode("utf8")


def stats(l):
    def avg(l):
        s = 0
        cnt = 0
        for item in l:
            s += item
            cnt += 1
        return round(s / cnt, 4)

    def med(l):
        return l[len(l)//2]

    return min(l), max(l), avg(l), med(l)



