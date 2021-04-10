#pragma once
#include <iostream>
#include <vector>

#include "igen_dd_lib.h"

#define LEN 1024

extern double* X;
extern dd_I* Y;

void verify();
void benchmark();

struct fn_t {
    void (*base_fn)(double*, double*);
    void (*fn)(dd_I*, dd_I*);
    std::string name;
    int ops;
};

extern std::vector<fn_t> functions;
