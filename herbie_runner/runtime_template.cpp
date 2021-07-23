#include "igen_lib.h"
#include "igen_math.h"
#include "tsc_x86.h"
#include <fenv.h>
#include <iostream>
#include <mpfr.h>

#define NUM_REPS 5000

f64_I global_res;

FUNCTION

double neg(const std::string & s) {
    if(s[0] == '-') {
        return std::stod(s.substr(1));
    }
    return std::stod("-" + s);
}

int main(int argc, char** argv) {
    fesetround(FE_UPWARD);

    BOUNDS_DECL
    F64I_DECL

    myInt64 start, end;

    for(int i = 0; i < NUM_REPS; ++i){
        global_res = FUNCALL
    }

    start = start_tsc();
    for(int i = 0; i < NUM_REPS; ++i){
        global_res = FUNCALL
    }
    end = stop_tsc(start);

    double time = end / NUM_REPS;
    std::cout << time << "\n";
    return 0;
}
