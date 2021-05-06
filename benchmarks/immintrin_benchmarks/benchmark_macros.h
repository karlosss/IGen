#pragma once

#include "common.h"

#define BENCHMARK(INTR, NAME) \
    static void INTR ## _ ## NAME ## _verify() {        \
        INTR ## _VERIFY(NAME);                          \
    }                                                   \
                                                        \
    static double INTR ## _ ## NAME ## _lat() {         \
        myInt64 start, end;                             \
        for(int i = 0; i < WARMUP_ITER; ++i){           \
            INTR ## _LAT(NAME);                         \
        }                                               \
        start = start_tsc();                            \
        INTR ## _LAT(NAME);                             \
        end = stop_tsc(start);                          \
        return end;                                     \
    }                                                   \
                                                        \
    static double INTR ## _ ## NAME ## _gap() {         \
        myInt64 start, end;                             \
        for(int i = 0; i < WARMUP_ITER; ++i){           \
            INTR ## _GAP(NAME);                         \
        }                                               \
        start = start_tsc();                            \
        INTR ## _GAP(NAME);                             \
        end = stop_tsc(start);                          \
        return end;                                     \
    }


#define ADD_FUNC(INTR, NAME, BASENAME, LAT_OPS, GAP_OPS) \
    set_globals();                                                                              \
    cout << "    " << #NAME << " verify: ";                                                     \
    verify(INTR ## _ ## BASENAME ## _verify, INTR ## _ ## NAME ## _verify);                     \
    set_globals();                                                                              \
    cout << "    " << #NAME << " latency: ";                                                    \
    cout << INTR ## _ ## NAME ## _lat() / LAT_OPS / BENCHMARK_ITER << " cycles" << endl;        \
    set_globals();                                                                              \
    cout << "    " << #NAME << " gap: ";                                                        \
    cout << INTR ## _ ## NAME ## _gap() / GAP_OPS / BENCHMARK_ITER << " cycles" << endl;
