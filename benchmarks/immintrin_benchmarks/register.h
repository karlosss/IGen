#pragma once

#include "benchmark_macros.h"

#include "benchmarks/mm256_add_pd.h"
#include "benchmarks/mm256_mul_pd.h"
#include "benchmarks/mm256_sub_pd.h"
#include "benchmarks/mm256_div_pd.h"
#include "benchmarks/mm256_fmadd_pd.h"

BENCHMARK(mm256_sub_pd, fb)
BENCHMARK(mm256_sub_pd, permute_no_unused_vals)

BENCHMARK(mm256_mul_pd, fb)
BENCHMARK(mm256_mul_pd, inlined_loop)
BENCHMARK(mm256_mul_pd, one_inlined_fn)
BENCHMARK(mm256_mul_pd, interleaved)
BENCHMARK(mm256_mul_pd, mul_fn)
BENCHMARK(mm256_mul_pd, no_interleave)
BENCHMARK(mm256_mul_pd, transposed)

BENCHMARK(mm256_add_pd, fb)
BENCHMARK(mm256_add_pd, forloop)
BENCHMARK(mm256_add_pd, inlined_loop)
BENCHMARK(mm256_add_pd, one_inlined_fn)
BENCHMARK(mm256_add_pd, interleaved)
BENCHMARK(mm256_add_pd, no_unused_vals)
BENCHMARK(mm256_add_pd, transposed)

BENCHMARK(mm256_div_pd, fb)
BENCHMARK(mm256_div_pd, inline_fn)
BENCHMARK(mm256_div_pd, transposed)
BENCHMARK(mm256_div_pd, transposed_avx_cond)

BENCHMARK(mm256_fmadd_pd, fb)
BENCHMARK(mm256_fmadd_pd, sep)
BENCHMARK(mm256_fmadd_pd, op)

static void register_functions() {
    // first one is the baseline function that is used to verify against

//    ADD_FUNC(mm256_sub_pd, fb, 2, 2)
//    ADD_FUNC(mm256_sub_pd, permute_no_unused_vals, 2, 2)
//
//    ADD_FUNC(mm256_mul_pd, fb, 16, 12)
//    ADD_FUNC(mm256_mul_pd, inlined_loop, 16, 12)
//    ADD_FUNC(mm256_mul_pd, one_inlined_fn, 16, 12)
//    ADD_FUNC(mm256_mul_pd, no_interleave, 16, 12)
//    ADD_FUNC(mm256_mul_pd, mul_fn, 16, 12)
//    ADD_FUNC(mm256_mul_pd, interleaved, 16, 12)
//    ADD_FUNC(mm256_mul_pd, transposed, 16, 12)
//
//    ADD_FUNC(mm256_add_pd, fb, 16, 12)
//    ADD_FUNC(mm256_add_pd, forloop, 16, 12)
//    ADD_FUNC(mm256_add_pd, inlined_loop, 16, 12)
//    ADD_FUNC(mm256_add_pd, one_inlined_fn, 16, 12)
//    ADD_FUNC(mm256_add_pd, interleaved, 16, 12)
//    ADD_FUNC(mm256_add_pd, no_unused_vals, 16, 12)
//    ADD_FUNC(mm256_add_pd, transposed, 16, 12)
//
    ADD_FUNC(mm256_div_pd, fb, 16, 12)
    ADD_FUNC(mm256_div_pd, inline_fn, 16, 12)
    ADD_FUNC(mm256_div_pd, transposed, 16, 12)
    ADD_FUNC(mm256_div_pd, transposed_avx_cond, 16, 12)

    ADD_FUNC(mm256_fmadd_pd, fb, 16, 12)
    ADD_FUNC(mm256_fmadd_pd, sep, 16, 12)
    ADD_FUNC(mm256_fmadd_pd, op, 16, 12)
}


//2 functions registered.
//Verify mm256_fmadd_pd
//sep... OK
//op... OK
//Verify mm256_div_pd
//inline_fn... OK
//transposed... OK
//transposed_avx_cond... OK
//Running benchmarks.
//Benchmark mm256_fmadd_pd
//fb latency: 394.413 cycles
//        fb gap: 389.084 cycles
//        sep latency: 155.695 cycles
//        sep gap: 141.717 cycles
//        op latency: 219.901 cycles
//        op gap: 213.278 cycles
//        Benchmark mm256_div_pd
//        fb latency: 767.383 cycles
//        fb gap: 123.311 cycles
//        inline_fn latency: 630.579 cycles
//        inline_fn gap: 32.317 cycles
//        transposed latency: 259.411 cycles
//        transposed gap: 267.577 cycles
//        transposed_avx_cond latency: 248.99 cycles
//        transposed_avx_cond gap: 242.179 cycles