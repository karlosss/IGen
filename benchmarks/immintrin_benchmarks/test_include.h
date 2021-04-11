#pragma once

#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"

void mm256_loadu_pd_base(double* in, double* out);
void mm256_loadu_pd_verify(dd_I* in, dd_I* out);
void mm256_loadu_pd_benchmark(dd_I* in, dd_I* out);

void mm256_load_pd_base(double* in, double* out);
void mm256_load_pd_verify(dd_I* in, dd_I* out);
void mm256_load_pd_benchmark(dd_I* in, dd_I* out);

void mm256_storeu_pd_base(double* in, double* out);
void mm256_storeu_pd_verify(dd_I* in, dd_I* out);
void mm256_storeu_pd_benchmark(dd_I* in, dd_I* out);

void mm256_store_pd_base(double* in, double* out);
void mm256_store_pd_verify(dd_I* in, dd_I* out);
void mm256_store_pd_benchmark(dd_I* in, dd_I* out);

void mm256_blend_pd_base(double* in, double* out);
void mm256_blend_pd_verify(dd_I* in, dd_I* out);
void mm256_blend_pd_benchmark(dd_I* in, dd_I* out);
