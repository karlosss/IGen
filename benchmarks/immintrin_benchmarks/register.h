#pragma once

#include "benchmark_macros.h"

BENCHMARK(mm256_mul_pd, fb)
BENCHMARK(mm256_mul_pd, forloop)
BENCHMARK(mm256_mul_pd, inlined_loop)

static void register_functions() {
    // first one is the baseline function that is used to verify against

    ADD_FUNC(mm256_mul_pd, fb, 16, 12)
    ADD_FUNC(mm256_mul_pd, forloop, 16, 12)
    ADD_FUNC(mm256_mul_pd, inlined_loop, 16, 12)
}