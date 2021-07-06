import os
from common import *

if sys.argv[1] == "-c":
    compile(os.path.basename(__file__)[:-3])

accuracy_herbie = []
runtime_herbie = []
accuracy_no_herbie = []
runtime_no_herbie = []

for i in range(100):
    x = random_double(-10, 10, 3)
    args = [x, x]
    accuracy_herbie.append(float(run_process(args, "accuracy").split(" ")[-1][:-1]))
    accuracy_no_herbie.append(float(run_process(args, "accuracy", False).split(" ")[-1][:-1]))
    runtime_herbie.append(int(run_process(args, "runtime")))
    runtime_no_herbie.append(int(run_process(args, "runtime", False)))

print("acc herbie:\tmin {:<10} max {:<10} avg {:<10} med {}".format(min(accuracy_herbie), max(accuracy_herbie), avg(accuracy_herbie), med(accuracy_herbie)))
print("acc no herbie:\tmin {:<10} max {:<10} avg {:<10} med {}".format(min(accuracy_no_herbie), max(accuracy_no_herbie), avg(accuracy_no_herbie), med(accuracy_no_herbie)))
print("run herbie:\tmin {:<10} max {:<10} avg {:<10} med {}".format(min(runtime_herbie), max(runtime_herbie), avg(runtime_herbie), med(runtime_herbie)))
print("run no herbie:\tmin {:<10} max {:<10} avg {:<10} med {}".format(min(runtime_no_herbie), max(runtime_no_herbie), avg(runtime_no_herbie), med(runtime_no_herbie)))
