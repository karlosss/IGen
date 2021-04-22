#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "igen_dd_lib.h"
#include "igen_dd_immintrin_types.h"
#include "igen_dd_immintrin.h"

#define LEN 4096
#define BENCHMARK_ITER 5000

using namespace std;

void verify();
void benchmark();
void init();

extern ddi_4* in_ddi4;
extern ddi_4* out_ddi4;
extern ddi_2* in_ddi2;
extern ddi_2* out_ddi2;
extern dd_I* in_ddi;
extern dd_I* out_ddi;
extern int* in_int0_15;
extern int* out_int0_15;
extern int* in_bool;
extern int* out_bool;

extern ddi_4 ddi40, ddi41, ddi42, ddi43, ddi44, ddi45, ddi46, ddi47, ddi48, ddi49, ddi410, ddi411, ddi412, ddi413, ddi414, ddi415;
extern ddi_2 ddi20, ddi21, ddi22, ddi23, ddi24, ddi25, ddi26, ddi27, ddi28, ddi29, ddi210, ddi211, ddi212, ddi213, ddi214, ddi215;
extern dd_I ddi0, ddi1, ddi2, ddi3, ddi4, ddi5, ddi6, ddi7, ddi8, ddi9, ddi10, ddi11, ddi12, ddi13, ddi14, ddi15;
extern int int0_150, int0_151, int0_152, int0_153, int0_154, int0_155, int0_156, int0_157, int0_158, int0_159, int0_1510, int0_1511, int0_1512, int0_1513, int0_1514, int0_1515;
extern int bool0, bool1, bool2, bool3, bool4, bool5, bool6, bool7, bool8, bool9, bool10, bool11, bool12, bool13, bool14, bool15;

struct fn_t {
    void (*latency_fn)();
    void (*gap_fn)();
    void (*verify_fn)();
    std::string name;
    double latency_ops;
    double gap_ops;
};

extern unordered_map<string, vector<fn_t>> functions;
