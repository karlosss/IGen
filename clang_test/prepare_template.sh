#!/bin/bash

bash compile_template.sh "$1" -R
bash compile_template.sh "$1"

cp tsc_x86.h /tmp

g++ /tmp/igen_herbie_accuracy.cpp -I "$(pwd)/../igen_lib" -lcrlibm -lmpfr -o /tmp/igen_herbie_accuracy
g++ /tmp/igen_accuracy.cpp -I "$(pwd)/../igen_lib" -lcrlibm -lmpfr -o /tmp/igen_accuracy
g++ /tmp/igen_herbie_runtime.cpp /tmp/tsc_x86.h -I "$(pwd)/../igen_lib" -lcrlibm -lmpfr -o /tmp/igen_herbie_runtime
g++ /tmp/igen_runtime.cpp /tmp/tsc_x86.h -I "$(pwd)/../igen_lib" -lcrlibm -lmpfr -o /tmp/igen_runtime
