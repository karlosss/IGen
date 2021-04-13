#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "igen_dd_lib.h"

#define LEN 1024

using namespace std;

void verify();
void benchmark();
void init();

extern dd_I in[LEN];
extern dd_I out[LEN];

struct fn_t {
    void (*latency_fn)();
    void (*gap_fn)();
    void (*verify_fn)();
    std::string name;
    int ops;
};

extern unordered_map<string, vector<fn_t>> functions;
