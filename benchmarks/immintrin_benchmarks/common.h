#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "igen_dd_lib.h"
#include "igen_dd_immintrin_types.h"

#define LEN 1024
#define BENCHMARK_ITER 5000

using namespace std;

void verify();
void benchmark();
void init();

extern ddi_4* in_ddi4;
extern ddi_4* out_ddi4;
extern dd_I* in_ddi;
extern dd_I* out_ddi;

extern ddi_4 ddi40, ddi41, ddi42, ddi43, ddi44, ddi45, ddi46, ddi47, ddi48, ddi49, ddi410, ddi411, ddi412, ddi413, ddi414, ddi415;
extern dd_I ddi0, ddi1, ddi2, ddi3, ddi4, ddi5, ddi6, ddi7, ddi8, ddi9, ddi10, ddi11, ddi12, ddi13, ddi14, ddi15;

struct fn_t {
    void (*latency_fn)();
    void (*gap_fn)();
    void (*verify_fn)();
    std::string name;
    double latency_ops;
    double gap_ops;
};

extern unordered_map<string, vector<fn_t>> functions;
