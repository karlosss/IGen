#include <iostream>
#include <cstring>
#include <list>

#include "tsc_x86.h"
#include "common.h"

#define CYCLES_REQUIRED 5e7
#define REP 30

using namespace std;

double benchFun(const fn_t & fn, dd_I* in, dd_I* out) {
    double cycles     =  0;
    long   num_runs   = 30;
    double multiplier =  1;
    myInt64 start, end;

    /* Warm-up phase */
    do {
        num_runs = num_runs * multiplier;
        start = start_tsc();
        for (int i = 0; i < num_runs; i++) {
            fn.fn(in, out);
        }
        end = stop_tsc(start);
        cycles = (double)end;
        multiplier = (CYCLES_REQUIRED) / (cycles);
    } while (multiplier > 2);

    list<double> cyclesList;

    // Actual performance measurements repeated REP times.
    for (size_t j = 0; j < REP; j++) {
        start = start_tsc();
        for (int i = 0; i < num_runs; ++i) {
            fn.fn(in, out);
        }
        end = stop_tsc(start);

        cycles = ((double)end) / num_runs;
        cyclesList.push_back(cycles);
    }

    cyclesList.sort();
    cycles = cyclesList.front();
    return cycles;
}

void benchmark() {
    cout << "Running benchmarks." << endl;

    dd_I* y = (dd_I*) aligned_alloc(32, LEN * sizeof(dd_I));
    for(int i = 0; i < functions.size(); ++i){
        cout << functions[i].name << "... ";
        double cycles = benchFun(functions[i], Y, y);
        double perf = functions[i].ops / cycles;
        cout << perf << " ops/cycle" << endl;
    }
    free(y);
}
