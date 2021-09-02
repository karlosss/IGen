#pragma once

static inline __attribute__((always_inline)) ddi_4 _igen_dd_permute_no_unused_vals_mm256_sub_pd(ddi_4 a, ddi_4 b) {
    ddi_4 _b;
    _b.f[0] = _mm256_permute4x64_pd(b.f[0], 0b01001110);
    _b.f[1] = _mm256_permute4x64_pd(b.f[1], 0b01001110);
    _b.f[2] = _mm256_permute4x64_pd(b.f[2], 0b01001110);
    _b.f[3] = _mm256_permute4x64_pd(b.f[3], 0b01001110);

    return _igen_dd_no_unused_vals_mm256_add_pd(a, _b);
}


static inline __attribute__((always_inline)) ddi_4 _igen_dd_transposed_mm256_sub_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif
    ddi_4 trans_a = _vec_transpose_ddi4(a);
    ddi_4 trans_b = _vec_transpose_ddi4(b);

    dd_v a_0 = trans_a.f[0];
    dd_v a_1 = trans_a.f[1];
    dd_v a_2 = trans_a.f[2];
    dd_v a_3 = trans_a.f[3];
    dd_v b_0 = trans_b.f[2];
    dd_v b_1 = trans_b.f[3];
    dd_v b_2 = trans_b.f[0];
    dd_v b_3 = trans_b.f[1];


#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif
    dd_v s0_0  = a_0 + b_0;
    dd_v s0_1  = a_1 + b_1;
    dd_v s0_2  = a_2 + b_2;
    dd_v s0_3  = a_3 + b_3;

    dd_v a0_0 = s0_0 - b_0;
    dd_v a0_1 = s0_1 - b_1;
    dd_v a0_2 = s0_2 - b_2;
    dd_v a0_3 = s0_3 - b_3;

    dd_v b0_0 = s0_0 - a0_0;
    dd_v b0_1 = s0_1 - a0_1;
    dd_v b0_2 = s0_2 - a0_2;
    dd_v b0_3 = s0_3 - a0_3;

    dd_v da0_0 = a_0 - a0_0;
    dd_v da0_1 = a_1 - a0_1;
    dd_v da0_2 = a_2 - a0_2;
    dd_v da0_3 = a_3 - a0_3;

    dd_v db0_0 = b_0 - b0_0;
    dd_v db0_1 = b_1 - b0_1;
    dd_v db0_2 = b_2 - b0_2;
    dd_v db0_3 = b_3 - b0_3;

    dd_v t0_0 = da0_0 + db0_0;
    dd_v t0_1 = da0_1 + db0_1;
    dd_v t0_2 = da0_2 + db0_2;
    dd_v t0_3 = da0_3 + db0_3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v c0_0 = t0_0 + s0_1;
    dd_v c0_2 = t0_2 + s0_3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f2s0_0 = s0_0 + c0_0;
    dd_v f2s0_2 = s0_2 + c0_2;

    dd_v f2z0_0 = f2s0_0 - s0_0;
    dd_v f2z0_2 = f2s0_2 - s0_2;

    dd_v f2t0_0 = c0_0 - f2z0_0;
    dd_v f2t0_2 = c0_2 - f2z0_2;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  w0_0    = t0_1 + f2t0_0;
    dd_v  w0_2    = t0_3 + f2t0_2;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f3s0_0 = f2s0_0 + w0_0;
    dd_v f3s0_2 = f2s0_2 + w0_2;

    dd_v f3z0_0 = f3s0_0 - f2s0_0;
    dd_v f3z0_2 = f3s0_2 - f2s0_2;

    dd_v f3t0_0 = w0_0 - f3z0_0;
    dd_v f3t0_2 = w0_2 - f3z0_2;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dst = _vec_transpose_m256d(f3s0_0, f3t0_0, f3s0_2, f3t0_2);

    return dst;
}

//#define _igen_dd_op_mm256_sub_pd _igen_dd_permute_no_unused_vals_mm256_sub_pd
#define _igen_dd_op_mm256_sub_pd _igen_dd_fb_mm256_sub_pd
