#pragma once

#include "common.h"

static void add_function(const string & base_name, const string & name,
                         void (*verify_fn)(), void (*latency_fn)(), void (*gap_fn)(),
                         int latency_ops, int gap_ops) {
    fn_t fn;
    fn.verify_fn = verify_fn;
    fn.latency_fn = latency_fn;
    fn.gap_fn = gap_fn;
    fn.name = name;
    fn.latency_ops = latency_ops;
    fn.gap_ops = gap_ops;

    if(functions.find(base_name) != functions.end()){
        functions[base_name].push_back(fn);
    }
    else{
        functions[base_name] = {fn};
    }
}

#define BENCHMARK(INTR, NAME) \
    INTR ## _VERIFY(NAME)     \
    INTR ## _LAT(NAME)        \
    INTR ## _GAP(NAME)        \


#define ADD_FUNC(INTR, NAME, LAT_OPS, GAP_OPS) \
    add_function(#INTR, #NAME, INTR ## _ ## NAME ## _verify, INTR ## _ ## NAME ## _lat, INTR ## _ ## NAME ## _gap, LAT_OPS, GAP_OPS);
