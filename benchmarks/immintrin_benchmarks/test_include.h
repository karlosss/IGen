#pragma once

#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"

void mm256_blend_pd_base(double* in, double* out);
void mm256_blend_pd(dd_I* in, dd_I* out);
