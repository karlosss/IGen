#pragma once

#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"

void mm256_blend_pd_fb_verify();
void mm256_blend_pd_fb_lat();
void mm256_blend_pd_fb_gap();

void mm256_blend_pd_opt_verify();
void mm256_blend_pd_opt_lat();
void mm256_blend_pd_opt_gap();
