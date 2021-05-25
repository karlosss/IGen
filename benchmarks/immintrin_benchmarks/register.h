#pragma once

#include "benchmark_macros.h"

#include "benchmarks/mm256_add_pd.h"
#include "benchmarks/mm256_mul_pd.h"

BENCHMARK(mm256_mul_pd, fb)
BENCHMARK(mm256_mul_pd, case_distinction_no_simd)

//BENCHMARK(mm256_mul_pd, inlined_loop)
//BENCHMARK(mm256_mul_pd, one_inlined_fn)
//BENCHMARK(mm256_mul_pd, interleaved)
//BENCHMARK(mm256_mul_pd, mul_fn)
//BENCHMARK(mm256_mul_pd, no_interleave)
//BENCHMARK(mm256_mul_pd, transposed)

//BENCHMARK(mm256_add_pd, fb)
//BENCHMARK(mm256_add_pd, forloop)
//BENCHMARK(mm256_add_pd, inlined_loop)
//BENCHMARK(mm256_add_pd, one_inlined_fn)
//BENCHMARK(mm256_add_pd, interleaved)
//BENCHMARK(mm256_add_pd, no_unused_vals)

static void register_functions() {
    // first one is the baseline function that is used to verify against

    ADD_FUNC(mm256_mul_pd, fb, 16, 12)
    ADD_FUNC(mm256_mul_pd, case_distinction_no_simd, 16, 12)
//    ADD_FUNC(mm256_mul_pd, inlined_loop, 16, 12)
//    ADD_FUNC(mm256_mul_pd, one_inlined_fn, 16, 12)
//    ADD_FUNC(mm256_mul_pd, no_interleave, 16, 12)
//    ADD_FUNC(mm256_mul_pd, mul_fn, 16, 12)
//    ADD_FUNC(mm256_mul_pd, interleaved, 16, 12)
//    ADD_FUNC(mm256_mul_pd, transposed, 16, 12)
//    ADD_FUNC(mm256_add_pd, fb, 16, 12)
//    ADD_FUNC(mm256_add_pd, forloop, 16, 12)
//    ADD_FUNC(mm256_add_pd, inlined_loop, 16, 12)
//    ADD_FUNC(mm256_add_pd, one_inlined_fn, 16, 12)
//    ADD_FUNC(mm256_add_pd, interleaved, 16, 12)
//    ADD_FUNC(mm256_add_pd, no_unused_vals, 16, 12)
}
