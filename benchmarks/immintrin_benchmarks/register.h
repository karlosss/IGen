#pragma once

#include "benchmark_macros.h"
#include "common.h"
#include "tsc_x86.h"

#include "benchmarks/mm256_mul_pd.h"

ddi_4 ddi40, ddi41, ddi42, ddi43, ddi44, ddi45, ddi46, ddi47, ddi48, ddi49, ddi410, ddi411, ddi412, ddi413, ddi414, ddi415;
ddi_2 ddi20, ddi21, ddi22, ddi23, ddi24, ddi25, ddi26, ddi27, ddi28, ddi29, ddi210, ddi211, ddi212, ddi213, ddi214, ddi215;
dd_I ddi0, ddi1, ddi2, ddi3, ddi4, ddi5, ddi6, ddi7, ddi8, ddi9, ddi10, ddi11, ddi12, ddi13, ddi14, ddi15;
int int0_150, int0_151, int0_152, int0_153, int0_154, int0_155, int0_156, int0_157, int0_158, int0_159, int0_1510, int0_1511, int0_1512, int0_1513, int0_1514, int0_1515;
int bool0, bool1, bool2, bool3, bool4, bool5, bool6, bool7, bool8, bool9, bool10, bool11, bool12, bool13, bool14, bool15;

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

    ddi20 = in_ddi2[0];
    ddi21 = in_ddi2[1];
    ddi22 = in_ddi2[2];
    ddi23 = in_ddi2[3];
    ddi24 = in_ddi2[4];
    ddi25 = in_ddi2[5];
    ddi26 = in_ddi2[6];
    ddi27 = in_ddi2[7];
    ddi28 = in_ddi2[8];
    ddi29 = in_ddi2[9];
    ddi210 = in_ddi2[10];
    ddi211 = in_ddi2[11];
    ddi212 = in_ddi2[12];
    ddi213 = in_ddi2[13];
    ddi214 = in_ddi2[14];
    ddi215 = in_ddi2[15];

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

    bool0 = in_bool[0];
    bool1 = in_bool[1];
    bool2 = in_bool[2];
    bool3 = in_bool[3];
    bool4 = in_bool[4];
    bool5 = in_bool[5];
    bool6= in_bool[6];
    bool7 = in_bool[7];
    bool8 = in_bool[8];
    bool9 = in_bool[9];
    bool10 = in_bool[10];
    bool11 = in_bool[11];
    bool12 = in_bool[12];
    bool13 = in_bool[13];
    bool14 = in_bool[14];
    bool15 = in_bool[15];
}

BENCHMARK(mm256_mul_pd, fb)
BENCHMARK(mm256_mul_pd, inlined_loop)
BENCHMARK(mm256_mul_pd, one_inlined_fn)
BENCHMARK(mm256_mul_pd, interleaved)
BENCHMARK(mm256_mul_pd, mul_fn)
BENCHMARK(mm256_mul_pd, no_interleave)
BENCHMARK(mm256_mul_pd, transposed)

void benchmark() {
    cout << "Running benchmarks." << endl;

    ADD_FUNC(mm256_mul_pd, fb, fb, 16, 12);
    ADD_FUNC(mm256_mul_pd, inlined_loop, fb, 16, 12);
    ADD_FUNC(mm256_mul_pd, one_inlined_fn, fb, 16, 12);
    ADD_FUNC(mm256_mul_pd, interleaved, fb, 16, 12);
    ADD_FUNC(mm256_mul_pd, mul_fn, fb, 16, 12);
    ADD_FUNC(mm256_mul_pd, no_interleave, fb, 16, 12);
    ADD_FUNC(mm256_mul_pd, transposed, fb, 16, 12);
}