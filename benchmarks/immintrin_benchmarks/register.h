#pragma once

#include "benchmark_macros.h"

#include "benchmarks/mm256_add_pd.h"
#include "benchmarks/mm256_mul_pd.h"
#include "benchmarks/mm256_blend_pd.h"

BENCHMARK(mm256_mul_pd, fb)
BENCHMARK(mm256_mul_pd, forloop)
BENCHMARK(mm256_mul_pd, inlined_loop)
BENCHMARK(mm256_mul_pd, one_inlined_fn)

BENCHMARK(mm256_blend_pd, fb)
BENCHMARK(mm256_blend_pd, op)

BENCHMARK(mm256_add_pd, fb)
BENCHMARK(mm256_add_pd, forloop)
BENCHMARK(mm256_add_pd, inlined_loop)
BENCHMARK(mm256_add_pd, op)

static void register_functions() {
    // first one is the baseline function that is used to verify against

    ADD_FUNC(mm256_mul_pd, fb, 16, 12)
    ADD_FUNC(mm256_mul_pd, forloop, 16, 12)
    ADD_FUNC(mm256_mul_pd, inlined_loop, 16, 12)
    ADD_FUNC(mm256_mul_pd, one_inlined_fn, 16, 12)

    ADD_FUNC(mm256_blend_pd, fb, 16, 12)
    ADD_FUNC(mm256_blend_pd, op, 16, 12)

    ADD_FUNC(mm256_add_pd, fb, 16, 12)
    ADD_FUNC(mm256_add_pd, forloop, 16, 12)
    ADD_FUNC(mm256_add_pd, inlined_loop, 16, 12)
    ADD_FUNC(mm256_add_pd, op, 16, 12)
}
