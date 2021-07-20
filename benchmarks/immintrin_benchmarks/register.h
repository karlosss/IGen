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

    ADD_FUNC(mm256_sub_pd, fb, 2, 2)
    ADD_FUNC(mm256_sub_pd, permute_no_unused_vals, 2, 2)

    ADD_FUNC(mm256_mul_pd, fb, 2, 2)
    ADD_FUNC(mm256_mul_pd, inlined_loop, 2, 2)
    ADD_FUNC(mm256_mul_pd, one_inlined_fn, 2, 2)
    ADD_FUNC(mm256_mul_pd, no_interleave, 2, 2)
    ADD_FUNC(mm256_mul_pd, mul_fn, 2, 2)
    ADD_FUNC(mm256_mul_pd, interleaved, 2, 2)
    ADD_FUNC(mm256_mul_pd, transposed, 2, 2)

    ADD_FUNC(mm256_add_pd, fb, 2, 2)
    ADD_FUNC(mm256_add_pd, forloop, 2, 2)
    ADD_FUNC(mm256_add_pd, inlined_loop, 2, 2)
    ADD_FUNC(mm256_add_pd, one_inlined_fn, 2, 2)
    ADD_FUNC(mm256_add_pd, interleaved, 2, 2)
    ADD_FUNC(mm256_add_pd, no_unused_vals, 2, 2)
    ADD_FUNC(mm256_add_pd, transposed, 2, 2)

    ADD_FUNC(mm256_div_pd, fb, 2, 2)
    ADD_FUNC(mm256_div_pd, inline_fn, 2, 2)
    ADD_FUNC(mm256_div_pd, transposed, 2, 2)
    ADD_FUNC(mm256_div_pd, transposed_avx_cond, 2, 2)

    ADD_FUNC(mm256_fmadd_pd, fb, 2, 2)
    ADD_FUNC(mm256_fmadd_pd, sep, 2, 2)
    ADD_FUNC(mm256_fmadd_pd, op, 2, 2)
}


//5 functions registered.
//Verify mm256_fmadd_pd
//sep... OK
//op... OK
//Verify mm256_div_pd
//inline_fn... OK
//transposed... OK
//transposed_avx_cond... OK
//Verify mm256_add_pd
//forloop... OK
//inlined_loop... OK
//one_inlined_fn... OK
//interleaved... OK
//no_unused_vals... OK
//transposed... OK
//Verify mm256_mul_pd
//inlined_loop... OK
//one_inlined_fn... OK
//no_interleave... OK
//mul_fn... OK
//interleaved... OK
//transposed... OK
//Verify mm256_sub_pd
//permute_no_unused_vals... OK
//Running benchmarks.
//Benchmark mm256_fmadd_pd
//fb latency: 391.654 cycles
//        fb gap: 390.184 cycles
//        sep latency: 145.116 cycles
//        sep gap: 114.078 cycles
//        op latency: 137.967 cycles
//        op gap: 101.703 cycles
//        Benchmark mm256_div_pd
//        fb latency: 765.413 cycles
//        fb gap: 123.695 cycles
//        inline_fn latency: 634.683 cycles
//        inline_fn gap: 32.4776 cycles
//        transposed latency: 91.727 cycles
//        transposed gap: 96.9296 cycles
//        transposed_avx_cond latency: 89.073 cycles
//        transposed_avx_cond gap: 79.7816 cycles
//        Benchmark mm256_add_pd
//        fb latency: 156.287 cycles
//        fb gap: 154.15 cycles
//        forloop latency: 55.3674 cycles
//        forloop gap: 33.5514 cycles
//        inlined_loop latency: 55.3542 cycles
//        inlined_loop gap: 33.4988 cycles
//        one_inlined_fn latency: 55.351 cycles
//        one_inlined_fn gap: 33.5226 cycles
//        interleaved latency: 53.516 cycles
//        interleaved gap: 35.5216 cycles
//        no_unused_vals latency: 59.0636 cycles
//        no_unused_vals gap: 32.6644 cycles
//        transposed latency: 68.333 cycles
//        transposed gap: 36.2058 cycles
//        Benchmark mm256_mul_pd
//        fb latency: 261.105 cycles
//        fb gap: 261.005 cycles
//        inlined_loop latency: 144.72 cycles
//        inlined_loop gap: 145.419 cycles
//        one_inlined_fn latency: 121.527 cycles
//        one_inlined_fn gap: 126.796 cycles
//        no_interleave latency: 210.534 cycles
//        no_interleave gap: 124.534 cycles
//        mul_fn latency: 121.564 cycles
//        mul_fn gap: 126.851 cycles
//        interleaved latency: 169.499 cycles
//        interleaved gap: 105.893 cycles
//        transposed latency: 85.972 cycles
//        transposed gap: 73.9132 cycles
//        Benchmark mm256_sub_pd
//        fb latency: 169.393 cycles
//        fb gap: 167.356 cycles
//        permute_no_unused_vals latency: 59.0644 cycles
//        permute_no_unused_vals gap: 31.7004 cycles