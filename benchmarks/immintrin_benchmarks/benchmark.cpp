#include <iostream>
#include <list>

#include "tsc_x86.h"
#include "common.h"

#define WARMUP_ITER 3000

using namespace std;

ddi_4 ddi40, ddi41, ddi42, ddi43, ddi44, ddi45, ddi46, ddi47, ddi48, ddi49, ddi410, ddi411, ddi412, ddi413, ddi414, ddi415;
dd_I ddi0, ddi1, ddi2, ddi3, ddi4, ddi5, ddi6, ddi7, ddi8, ddi9, ddi10, ddi11, ddi12, ddi13, ddi14, ddi15;
int int0_150, int0_151, int0_152, int0_153, int0_154, int0_155, int0_156, int0_157, int0_158, int0_159, int0_1510, int0_1511, int0_1512, int0_1513, int0_1514, int0_1515;

void set_globals() {
    ddi40 = in_ddi4[0];
    ddi41 = in_ddi4[1];
    ddi42 = in_ddi4[2];
    ddi43 = in_ddi4[3];
    ddi44 = in_ddi4[4];
    ddi45 = in_ddi4[5];
    ddi46 = in_ddi4[6];
    ddi47 = in_ddi4[7];
    ddi48 = in_ddi4[8];
    ddi49 = in_ddi4[9];
    ddi410 = in_ddi4[10];
    ddi411 = in_ddi4[11];
    ddi412 = in_ddi4[12];
    ddi413 = in_ddi4[13];
    ddi414 = in_ddi4[14];
    ddi415 = in_ddi4[15];

    ddi0 = in_ddi[0];
    ddi1 = in_ddi[1];
    ddi2 = in_ddi[2];
    ddi3 = in_ddi[3];
    ddi4 = in_ddi[4];
    ddi5 = in_ddi[5];
    ddi6 = in_ddi[6];
    ddi7 = in_ddi[7];
    ddi8 = in_ddi[8];
    ddi9 = in_ddi[9];
    ddi10 = in_ddi[10];
    ddi11 = in_ddi[11];
    ddi12 = in_ddi[12];
    ddi13 = in_ddi[13];
    ddi14 = in_ddi[14];
    ddi15 = in_ddi[15];

    int0_150 = in_int0_15[0];
    int0_151 = in_int0_15[1];
    int0_152 = in_int0_15[2];
    int0_153 = in_int0_15[3];
    int0_154 = in_int0_15[4];
    int0_155 = in_int0_15[5];
    int0_156 = in_int0_15[6];
    int0_157 = in_int0_15[7];
    int0_158 = in_int0_15[8];
    int0_159 = in_int0_15[9];
    int0_1510 = in_int0_15[10];
    int0_1511 = in_int0_15[11];
    int0_1512 = in_int0_15[12];
    int0_1513 = in_int0_15[13];
    int0_1514 = in_int0_15[14];
    int0_1515 = in_int0_15[15];
}

double benchFun(void (*fn)()) {
    myInt64 start, end;

    for(int i = 0; i < WARMUP_ITER; ++i){
        fn();
    }

    start = start_tsc();
    fn();
    end = stop_tsc(start);

    return end;
}

void benchmark() {
    cout << "Running benchmarks." << endl;

    for(auto it = functions.begin(); it != functions.end(); ++it){
        cout << "Benchmark " << it->first << endl;

        for(int i = 0; i < it->second.size(); ++i){
            set_globals();

            cout << "    " << it->second[i].name << " latency: ";
            cout << benchFun(it->second[i].latency_fn) / it->second[i].latency_ops / BENCHMARK_ITER << " cycles" << endl;
            cout << "    " << it->second[i].name << " gap: ";
            cout << benchFun(it->second[i].gap_fn) / it->second[i].gap_ops / BENCHMARK_ITER << " cycles" << endl;
        }
    }
}
