#pragma once
#include <cmath>

static inline __attribute__((always_inline)) ddi_4 _igen_dd_inlined_loop_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_mul_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_mul_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_mul_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_mul_dd(a.f[3], b.f[3]);

    return dst;
}

static inline __attribute__((always_inline)) dd_v mul(dd_I af0, dd_I bf0) {
    dd_I _b = _mm256_permute4x64_pd(bf0, 0b01001110);

    dd_v  ah = _mm256_unpacklo_pd(af0, af0);
    dd_v  al = _mm256_unpackhi_pd(af0, af0);
    dd_v  bh = _mm256_unpacklo_pd(bf0, -_b);
    dd_v  bl = _mm256_unpackhi_pd(bf0, -_b);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3  = ah * bh;
    dd_v t_3  = _mm256_fmsub_pd(ah, bh, s_3);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    dd2_v r_3;
    r_3.h = s_3;
    r_3.l = t_3;

    dd2_v c = r_3;

    dd_v  tl0 = al * bl;
    dd_v  tl1 = _mm256_fmadd_pd(ah, bl, tl0);
    dd_v  cl2 = _mm256_fmadd_pd(al, bh, tl1);
    dd_v  cl3 = c.l + cl2;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4 = c.h + cl3;
    dd_v z_4 = s_4 - c.h;
    dd_v t_4 = cl3 - z_4;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd2_v r_4;
    r_4.h = s_4;
    r_4.l = t_4;
    dd2_v z = r_4;

    dd_ddavx_I r;
    r._1 = _mm256_unpacklo_pd(z.h, z.l);
    r._2 = _mm256_unpackhi_pd(z.h, z.l);

    dd_ddavx_I _r_up = r;

    dd_v  ah_2 = _mm256_unpacklo_pd(af0, af0);
    dd_v  al_2 = _mm256_unpackhi_pd(af0, af0);
    dd_v  bh_2 = _mm256_unpacklo_pd(-bf0, _b);
    dd_v  bl_2 = _mm256_unpackhi_pd(-bf0, _b);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5  = ah_2 * bh_2;
    dd_v t_5  = _mm256_fmsub_pd(ah_2, bh_2, s_5);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    dd2_v r_5;
    r_5.h = s_5;
    r_5.l = t_5;

    dd2_v c_2 = r_5;

    dd_v  tl0_2 = al_2 * bl_2;
    dd_v  tl1_2 = _mm256_fmadd_pd(ah_2, bl_2, tl0_2);
    dd_v  cl2_2 = _mm256_fmadd_pd(al_2, bh_2, tl1_2);
    dd_v  cl3_2 = c_2.l + cl2_2;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6 = c_2.h + cl3_2;
    dd_v z_6 = s_6 - c_2.h;
    dd_v t_6 = cl3_2 - z_6;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd2_v r_6;
    r_6.h = s_6;
    r_6.l = t_6;
    dd2_v z_2 = r_6;

    dd_ddavx_I r_2;
    r_2._1 = _mm256_unpacklo_pd(z_2.h, z_2.l);
    r_2._2 = _mm256_unpackhi_pd(z_2.h, z_2.l);
    dd_ddavx_I _r_lo = r_2;

    dd_v minf_7, mask1_7, mask2_7, _a_7, _b_7, c_7;

    /* Create -inf vector */
    minf_7  = _mm256_set1_pd(-1.0/0.0);

    mask1_7 = _mm256_cmp_pd(_r_up._1, _r_up._2, _CMP_GE_OQ);
    mask2_7 = _mm256_cmp_pd(_r_up._1, _r_up._2, _CMP_LE_OQ);

    mask1_7 = _mm256_unpacklo_pd(mask1_7, mask1_7);
    mask2_7 = _mm256_unpacklo_pd(mask2_7, mask2_7);

    _a_7 = _mm256_blendv_pd(minf_7, _r_up._1, mask1_7);
    _b_7 = _mm256_blendv_pd(minf_7, _r_up._2, mask2_7);

    c_7 = _mm256_max_pd(_a_7, _b_7);

    dd_I r_up = c_7;

    dd_v minf_8, mask1_8, mask2_8, _a_8, _b_8, c_8;

    /* Create -inf vector */
    minf_8  = _mm256_set1_pd(-1.0/0.0);

    mask1_8 = _mm256_cmp_pd(_r_lo._1, _r_lo._2, _CMP_GE_OQ);
    mask2_8 = _mm256_cmp_pd(_r_lo._1, _r_lo._2, _CMP_LE_OQ);

    mask1_8 = _mm256_unpacklo_pd(mask1_8, mask1_8);
    mask2_8 = _mm256_unpacklo_pd(mask2_8, mask2_8);

    _a_8 = _mm256_blendv_pd(minf_8, _r_lo._1, mask1_8);
    _b_8 = _mm256_blendv_pd(minf_8, _r_lo._2, mask2_8);

    c_8 = _mm256_max_pd(_a_8, _b_8);

    dd_I r_lo = c_8;

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1 = _mm256_permute2f128_pd(r_lo, r_up, 0b00100000);
    dd_I c2 = _mm256_permute2f128_pd(r_lo, r_up, 0b00110001);

    dd_v minf_9, mask1_9, mask2_9, _a_9, _b_9, c_9;

    /* Create -inf vector */
    minf_9  = _mm256_set1_pd(-1.0/0.0);

    mask1_9 = _mm256_cmp_pd(c1, c2, _CMP_GE_OQ);
    mask2_9 = _mm256_cmp_pd(c1, c2, _CMP_LE_OQ);

    mask1_9 = _mm256_unpacklo_pd(mask1_9, mask1_9);
    mask2_9 = _mm256_unpacklo_pd(mask2_9, mask2_9);

    _a_9 = _mm256_blendv_pd(minf_9, c1, mask1_9);
    _b_9 = _mm256_blendv_pd(minf_9, c2, mask2_9);

    c_9 = _mm256_max_pd(_a_9, _b_9);
    return c_9;
}

static inline __attribute__((always_inline)) ddi_4 _igen_dd_mul_fn_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = mul(a.f[0], b.f[0]);
    dst.f[1] = mul(a.f[1], b.f[1]);
    dst.f[2] = mul(a.f[2], b.f[2]);
    dst.f[3] = mul(a.f[3], b.f[3]);

    return dst;
}

static inline __attribute__((always_inline)) ddi_4 _igen_dd_one_inlined_fn_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dd_I af0 = a.f[0];
    dd_I bf0 = b.f[0];

    dd_I _b = _mm256_permute4x64_pd(bf0, 0b01001110);

    dd_v  ah = _mm256_unpacklo_pd(af0, af0);
    dd_v  al = _mm256_unpackhi_pd(af0, af0);
    dd_v  bh = _mm256_unpacklo_pd(bf0, -_b);
    dd_v  bl = _mm256_unpackhi_pd(bf0, -_b);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3  = ah * bh;
    dd_v t_3  = _mm256_fmsub_pd(ah, bh, s_3);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    dd2_v r_3;
    r_3.h = s_3;
    r_3.l = t_3;

    dd2_v c = r_3;

    dd_v  tl0 = al * bl;
    dd_v  tl1 = _mm256_fmadd_pd(ah, bl, tl0);
    dd_v  cl2 = _mm256_fmadd_pd(al, bh, tl1);
    dd_v  cl3 = c.l + cl2;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4 = c.h + cl3;
    dd_v z_4 = s_4 - c.h;
    dd_v t_4 = cl3 - z_4;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd2_v r_4;
    r_4.h = s_4;
    r_4.l = t_4;
    dd2_v z = r_4;

    dd_ddavx_I r;
    r._1 = _mm256_unpacklo_pd(z.h, z.l);
    r._2 = _mm256_unpackhi_pd(z.h, z.l);

    dd_ddavx_I _r_up = r;

    dd_v  ah_2 = _mm256_unpacklo_pd(af0, af0);
    dd_v  al_2 = _mm256_unpackhi_pd(af0, af0);
    dd_v  bh_2 = _mm256_unpacklo_pd(-bf0, _b);
    dd_v  bl_2 = _mm256_unpackhi_pd(-bf0, _b);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5  = ah_2 * bh_2;
    dd_v t_5  = _mm256_fmsub_pd(ah_2, bh_2, s_5);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    dd2_v r_5;
    r_5.h = s_5;
    r_5.l = t_5;

    dd2_v c_2 = r_5;

    dd_v  tl0_2 = al_2 * bl_2;
    dd_v  tl1_2 = _mm256_fmadd_pd(ah_2, bl_2, tl0_2);
    dd_v  cl2_2 = _mm256_fmadd_pd(al_2, bh_2, tl1_2);
    dd_v  cl3_2 = c_2.l + cl2_2;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6 = c_2.h + cl3_2;
    dd_v z_6 = s_6 - c_2.h;
    dd_v t_6 = cl3_2 - z_6;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd2_v r_6;
    r_6.h = s_6;
    r_6.l = t_6;
    dd2_v z_2 = r_6;

    dd_ddavx_I r_2;
    r_2._1 = _mm256_unpacklo_pd(z_2.h, z_2.l);
    r_2._2 = _mm256_unpackhi_pd(z_2.h, z_2.l);
    dd_ddavx_I _r_lo = r_2;

    dd_v minf_7, mask1_7, mask2_7, _a_7, _b_7, c_7;

    /* Create -inf vector */
    minf_7  = _mm256_set1_pd(-1.0/0.0);

    mask1_7 = _mm256_cmp_pd(_r_up._1, _r_up._2, _CMP_GE_OQ);
    mask2_7 = _mm256_cmp_pd(_r_up._1, _r_up._2, _CMP_LE_OQ);

    mask1_7 = _mm256_unpacklo_pd(mask1_7, mask1_7);
    mask2_7 = _mm256_unpacklo_pd(mask2_7, mask2_7);

    _a_7 = _mm256_blendv_pd(minf_7, _r_up._1, mask1_7);
    _b_7 = _mm256_blendv_pd(minf_7, _r_up._2, mask2_7);

    c_7 = _mm256_max_pd(_a_7, _b_7);

    dd_I r_up = c_7;

    dd_v minf_8, mask1_8, mask2_8, _a_8, _b_8, c_8;

    /* Create -inf vector */
    minf_8  = _mm256_set1_pd(-1.0/0.0);

    mask1_8 = _mm256_cmp_pd(_r_lo._1, _r_lo._2, _CMP_GE_OQ);
    mask2_8 = _mm256_cmp_pd(_r_lo._1, _r_lo._2, _CMP_LE_OQ);

    mask1_8 = _mm256_unpacklo_pd(mask1_8, mask1_8);
    mask2_8 = _mm256_unpacklo_pd(mask2_8, mask2_8);

    _a_8 = _mm256_blendv_pd(minf_8, _r_lo._1, mask1_8);
    _b_8 = _mm256_blendv_pd(minf_8, _r_lo._2, mask2_8);

    c_8 = _mm256_max_pd(_a_8, _b_8);

    dd_I r_lo = c_8;

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1 = _mm256_permute2f128_pd(r_lo, r_up, 0b00100000);
    dd_I c2 = _mm256_permute2f128_pd(r_lo, r_up, 0b00110001);

    dd_v minf_9, mask1_9, mask2_9, _a_9, _b_9, c_9;

    /* Create -inf vector */
    minf_9  = _mm256_set1_pd(-1.0/0.0);

    mask1_9 = _mm256_cmp_pd(c1, c2, _CMP_GE_OQ);
    mask2_9 = _mm256_cmp_pd(c1, c2, _CMP_LE_OQ);

    mask1_9 = _mm256_unpacklo_pd(mask1_9, mask1_9);
    mask2_9 = _mm256_unpacklo_pd(mask2_9, mask2_9);

    _a_9 = _mm256_blendv_pd(minf_9, c1, mask1_9);
    _b_9 = _mm256_blendv_pd(minf_9, c2, mask2_9);

    c_9 = _mm256_max_pd(_a_9, _b_9);

    dst.f[0] = c_9;


    dst.f[1] = mul(a.f[1], b.f[1]);
    dst.f[2] = mul(a.f[2], b.f[2]);
    dst.f[3] = mul(a.f[3], b.f[3]);

    return dst;
}

static inline __attribute__((always_inline)) ddi_4 _igen_dd_no_interleave_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dd_I af0_0_ = a.f[0];
    dd_I af0_1_ = a.f[1];
    dd_I af0_2_ = a.f[2];
    dd_I af0_3_ = a.f[3];

    dd_I bf0_0_ = b.f[0];
    dd_I bf0_1_ = b.f[1];
    dd_I bf0_2_ = b.f[2];
    dd_I bf0_3_ = b.f[3];

    dd_I _b_0_ = -_mm256_permute4x64_pd(bf0_0_, 0b01001110);

    dd_v  ah_0_ = _mm256_unpacklo_pd(af0_0_, af0_0_);
    dd_v  al_0_ = _mm256_unpackhi_pd(af0_0_, af0_0_);
    dd_v  bh_0_ = _mm256_unpacklo_pd(bf0_0_, _b_0_);
    dd_v  bl_0_ = _mm256_unpackhi_pd(bf0_0_, _b_0_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_0_  = ah_0_ * bh_0_;
    dd_v t_3_0_  = _mm256_fmsub_pd(ah_0_, bh_0_, s_3_0_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_0_ = al_0_ * bl_0_;
    dd_v  tl1_0_ = _mm256_fmadd_pd(ah_0_, bl_0_, tl0_0_);
    dd_v  cl2_0_ = _mm256_fmadd_pd(al_0_, bh_0_, tl1_0_);
    dd_v  cl3_0_ = t_3_0_ + cl2_0_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_0_ = s_3_0_ + cl3_0_;
    dd_v z_4_0_ = s_4_0_ - s_3_0_;
    dd_v t_4_0_ = cl3_0_ - z_4_0_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_0_ = _mm256_unpacklo_pd(s_4_0_, t_4_0_);
    __m256d _r_up_2_0_ = _mm256_unpackhi_pd(s_4_0_, t_4_0_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_0_  = ah_0_ * (-bh_0_);
    dd_v t_5_0_  = _mm256_fmsub_pd(ah_0_, -bh_0_, s_5_0_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_0_ = al_0_ * (-bl_0_);
    dd_v  tl1_2_0_ = _mm256_fmadd_pd(ah_0_, -bl_0_, tl0_2_0_);
    dd_v  cl2_2_0_ = _mm256_fmadd_pd(al_0_, -bh_0_, tl1_2_0_);
    dd_v  cl3_2_0_ = t_5_0_ + cl2_2_0_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_0_ = s_5_0_ + cl3_2_0_;
    dd_v z_6_0_ = s_6_0_ - s_5_0_;
    dd_v t_6_0_ = cl3_2_0_ - z_6_0_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_0_ = _mm256_unpacklo_pd(s_6_0_, t_6_0_);
    __m256d _r_lo_2_0_ = _mm256_unpackhi_pd(s_6_0_, t_6_0_);

    /* Create -inf vector */
    dd_v minf = _mm256_set1_pd(-1.0/0.0);

    dd_v mask1_7_0_ = _mm256_cmp_pd(_r_up_1_0_, _r_up_2_0_, _CMP_GE_OQ);
    dd_v mask2_7_0_ = _mm256_cmp_pd(_r_up_1_0_, _r_up_2_0_, _CMP_LE_OQ);

    mask1_7_0_ = _mm256_unpacklo_pd(mask1_7_0_, mask1_7_0_);
    mask2_7_0_ = _mm256_unpacklo_pd(mask2_7_0_, mask2_7_0_);

    dd_v _a_7_0_ = _mm256_blendv_pd(minf, _r_up_1_0_, mask1_7_0_);
    dd_v _b_7_0_ = _mm256_blendv_pd(minf, _r_up_2_0_, mask2_7_0_);

    dd_I r_up_0_ = _mm256_max_pd(_a_7_0_, _b_7_0_);

    dd_v mask1_8_0_ = _mm256_cmp_pd(_r_lo_1_0_, _r_lo_2_0_, _CMP_GE_OQ);
    dd_v mask2_8_0_ = _mm256_cmp_pd(_r_lo_1_0_, _r_lo_2_0_, _CMP_LE_OQ);

    mask1_8_0_ = _mm256_unpacklo_pd(mask1_8_0_, mask1_8_0_);
    mask2_8_0_ = _mm256_unpacklo_pd(mask2_8_0_, mask2_8_0_);

    dd_v _a_8_0_ = _mm256_blendv_pd(minf, _r_lo_1_0_, mask1_8_0_);
    dd_v _b_8_0_ = _mm256_blendv_pd(minf, _r_lo_2_0_, mask2_8_0_);

    dd_I r_lo_0_ = _mm256_max_pd(_a_8_0_, _b_8_0_);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_0_ = _mm256_permute2f128_pd(r_lo_0_, r_up_0_, 0b00100000);
    dd_I c2_0_ = _mm256_permute2f128_pd(r_lo_0_, r_up_0_, 0b00110001);

    dd_v mask1_9_0_ = _mm256_cmp_pd(c1_0_, c2_0_, _CMP_GE_OQ);
    dd_v mask2_9_0_ = _mm256_cmp_pd(c1_0_, c2_0_, _CMP_LE_OQ);

    mask1_9_0_ = _mm256_unpacklo_pd(mask1_9_0_, mask1_9_0_);
    mask2_9_0_ = _mm256_unpacklo_pd(mask2_9_0_, mask2_9_0_);

    dd_v _a_9_0_ = _mm256_blendv_pd(minf, c1_0_, mask1_9_0_);
    dd_v _b_9_0_ = _mm256_blendv_pd(minf, c2_0_, mask2_9_0_);

    // ======

    dd_I _b_1_ = -_mm256_permute4x64_pd(bf0_1_, 0b01001110);

    dd_v  ah_1_ = _mm256_unpacklo_pd(af0_1_, af0_1_);
    dd_v  al_1_ = _mm256_unpackhi_pd(af0_1_, af0_1_);
    dd_v  bh_1_ = _mm256_unpacklo_pd(bf0_1_, _b_1_);
    dd_v  bl_1_ = _mm256_unpackhi_pd(bf0_1_, _b_1_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_1_  = ah_1_ * bh_1_;
    dd_v t_3_1_  = _mm256_fmsub_pd(ah_1_, bh_1_, s_3_1_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_1_ = al_1_ * bl_1_;
    dd_v  tl1_1_ = _mm256_fmadd_pd(ah_1_, bl_1_, tl0_1_);
    dd_v  cl2_1_ = _mm256_fmadd_pd(al_1_, bh_1_, tl1_1_);
    dd_v  cl3_1_ = t_3_1_ + cl2_1_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_1_ = s_3_1_ + cl3_1_;
    dd_v z_4_1_ = s_4_1_ - s_3_1_;
    dd_v t_4_1_ = cl3_1_ - z_4_1_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_1_ = _mm256_unpacklo_pd(s_4_1_, t_4_1_);
    __m256d _r_up_2_1_ = _mm256_unpackhi_pd(s_4_1_, t_4_1_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_1_  = ah_1_ * (-bh_1_);
    dd_v t_5_1_  = _mm256_fmsub_pd(ah_1_, -bh_1_, s_5_1_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_1_ = al_1_ * (-bl_1_);
    dd_v  tl1_2_1_ = _mm256_fmadd_pd(ah_1_, -bl_1_, tl0_2_1_);
    dd_v  cl2_2_1_ = _mm256_fmadd_pd(al_1_, -bh_1_, tl1_2_1_);
    dd_v  cl3_2_1_ = t_5_1_ + cl2_2_1_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_1_ = s_5_1_ + cl3_2_1_;
    dd_v z_6_1_ = s_6_1_ - s_5_1_;
    dd_v t_6_1_ = cl3_2_1_ - z_6_1_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_1_ = _mm256_unpacklo_pd(s_6_1_, t_6_1_);
    __m256d _r_lo_2_1_ = _mm256_unpackhi_pd(s_6_1_, t_6_1_);

    /* Create -inf vector */

    dd_v mask1_7_1_ = _mm256_cmp_pd(_r_up_1_1_, _r_up_2_1_, _CMP_GE_OQ);
    dd_v mask2_7_1_ = _mm256_cmp_pd(_r_up_1_1_, _r_up_2_1_, _CMP_LE_OQ);

    mask1_7_1_ = _mm256_unpacklo_pd(mask1_7_1_, mask1_7_1_);
    mask2_7_1_ = _mm256_unpacklo_pd(mask2_7_1_, mask2_7_1_);

    dd_v _a_7_1_ = _mm256_blendv_pd(minf, _r_up_1_1_, mask1_7_1_);
    dd_v _b_7_1_ = _mm256_blendv_pd(minf, _r_up_2_1_, mask2_7_1_);

    dd_I r_up_1_ = _mm256_max_pd(_a_7_1_, _b_7_1_);

    dd_v mask1_8_1_ = _mm256_cmp_pd(_r_lo_1_1_, _r_lo_2_1_, _CMP_GE_OQ);
    dd_v mask2_8_1_ = _mm256_cmp_pd(_r_lo_1_1_, _r_lo_2_1_, _CMP_LE_OQ);

    mask1_8_1_ = _mm256_unpacklo_pd(mask1_8_1_, mask1_8_1_);
    mask2_8_1_ = _mm256_unpacklo_pd(mask2_8_1_, mask2_8_1_);

    dd_v _a_8_1_ = _mm256_blendv_pd(minf, _r_lo_1_1_, mask1_8_1_);
    dd_v _b_8_1_ = _mm256_blendv_pd(minf, _r_lo_2_1_, mask2_8_1_);

    dd_I r_lo_1_ = _mm256_max_pd(_a_8_1_, _b_8_1_);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_1_ = _mm256_permute2f128_pd(r_lo_1_, r_up_1_, 0b00100000);
    dd_I c2_1_ = _mm256_permute2f128_pd(r_lo_1_, r_up_1_, 0b00110001);

    dd_v mask1_9_1_ = _mm256_cmp_pd(c1_1_, c2_1_, _CMP_GE_OQ);
    dd_v mask2_9_1_ = _mm256_cmp_pd(c1_1_, c2_1_, _CMP_LE_OQ);

    mask1_9_1_ = _mm256_unpacklo_pd(mask1_9_1_, mask1_9_1_);
    mask2_9_1_ = _mm256_unpacklo_pd(mask2_9_1_, mask2_9_1_);

    dd_v _a_9_1_ = _mm256_blendv_pd(minf, c1_1_, mask1_9_1_);
    dd_v _b_9_1_ = _mm256_blendv_pd(minf, c2_1_, mask2_9_1_);

    // ======

    dd_I _b_2_ = -_mm256_permute4x64_pd(bf0_2_, 0b01001110);

    dd_v  ah_2_ = _mm256_unpacklo_pd(af0_2_, af0_2_);
    dd_v  al_2_ = _mm256_unpackhi_pd(af0_2_, af0_2_);
    dd_v  bh_2_ = _mm256_unpacklo_pd(bf0_2_, _b_2_);
    dd_v  bl_2_ = _mm256_unpackhi_pd(bf0_2_, _b_2_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_2_  = ah_2_ * bh_2_;
    dd_v t_3_2_  = _mm256_fmsub_pd(ah_2_, bh_2_, s_3_2_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_ = al_2_ * bl_2_;
    dd_v  tl1_2_ = _mm256_fmadd_pd(ah_2_, bl_2_, tl0_2_);
    dd_v  cl2_2_ = _mm256_fmadd_pd(al_2_, bh_2_, tl1_2_);
    dd_v  cl3_2_ = t_3_2_ + cl2_2_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_2_ = s_3_2_ + cl3_2_;
    dd_v z_4_2_ = s_4_2_ - s_3_2_;
    dd_v t_4_2_ = cl3_2_ - z_4_2_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_2_ = _mm256_unpacklo_pd(s_4_2_, t_4_2_);
    __m256d _r_up_2_2_ = _mm256_unpackhi_pd(s_4_2_, t_4_2_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_2_  = ah_2_ * (-bh_2_);
    dd_v t_5_2_  = _mm256_fmsub_pd(ah_2_, -bh_2_, s_5_2_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_2_ = al_2_ * (-bl_2_);
    dd_v  tl1_2_2_ = _mm256_fmadd_pd(ah_2_, -bl_2_, tl0_2_2_);
    dd_v  cl2_2_2_ = _mm256_fmadd_pd(al_2_, -bh_2_, tl1_2_2_);
    dd_v  cl3_2_2_ = t_5_2_ + cl2_2_2_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_2_ = s_5_2_ + cl3_2_2_;
    dd_v z_6_2_ = s_6_2_ - s_5_2_;
    dd_v t_6_2_ = cl3_2_2_ - z_6_2_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_2_ = _mm256_unpacklo_pd(s_6_2_, t_6_2_);
    __m256d _r_lo_2_2_ = _mm256_unpackhi_pd(s_6_2_, t_6_2_);

    /* Create -inf vector */

    dd_v mask1_7_2_ = _mm256_cmp_pd(_r_up_1_2_, _r_up_2_2_, _CMP_GE_OQ);
    dd_v mask2_7_2_ = _mm256_cmp_pd(_r_up_1_2_, _r_up_2_2_, _CMP_LE_OQ);

    mask1_7_2_ = _mm256_unpacklo_pd(mask1_7_2_, mask1_7_2_);
    mask2_7_2_ = _mm256_unpacklo_pd(mask2_7_2_, mask2_7_2_);

    dd_v _a_7_2_ = _mm256_blendv_pd(minf, _r_up_1_2_, mask1_7_2_);
    dd_v _b_7_2_ = _mm256_blendv_pd(minf, _r_up_2_2_, mask2_7_2_);

    dd_I r_up_2_ = _mm256_max_pd(_a_7_2_, _b_7_2_);

    dd_v mask1_8_2_ = _mm256_cmp_pd(_r_lo_1_2_, _r_lo_2_2_, _CMP_GE_OQ);
    dd_v mask2_8_2_ = _mm256_cmp_pd(_r_lo_1_2_, _r_lo_2_2_, _CMP_LE_OQ);

    mask1_8_2_ = _mm256_unpacklo_pd(mask1_8_2_, mask1_8_2_);
    mask2_8_2_ = _mm256_unpacklo_pd(mask2_8_2_, mask2_8_2_);

    dd_v _a_8_2_ = _mm256_blendv_pd(minf, _r_lo_1_2_, mask1_8_2_);
    dd_v _b_8_2_ = _mm256_blendv_pd(minf, _r_lo_2_2_, mask2_8_2_);

    dd_I r_lo_2_ = _mm256_max_pd(_a_8_2_, _b_8_2_);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_2_ = _mm256_permute2f128_pd(r_lo_2_, r_up_2_, 0b00100000);
    dd_I c2_2_ = _mm256_permute2f128_pd(r_lo_2_, r_up_2_, 0b00110001);

    dd_v mask1_9_2_ = _mm256_cmp_pd(c1_2_, c2_2_, _CMP_GE_OQ);
    dd_v mask2_9_2_ = _mm256_cmp_pd(c1_2_, c2_2_, _CMP_LE_OQ);

    mask1_9_2_ = _mm256_unpacklo_pd(mask1_9_2_, mask1_9_2_);
    mask2_9_2_ = _mm256_unpacklo_pd(mask2_9_2_, mask2_9_2_);

    dd_v _a_9_2_ = _mm256_blendv_pd(minf, c1_2_, mask1_9_2_);
    dd_v _b_9_2_ = _mm256_blendv_pd(minf, c2_2_, mask2_9_2_);

    // ======

    dd_I _b_3_ = -_mm256_permute4x64_pd(bf0_3_, 0b01001110);

    dd_v  ah_3_ = _mm256_unpacklo_pd(af0_3_, af0_3_);
    dd_v  al_3_ = _mm256_unpackhi_pd(af0_3_, af0_3_);
    dd_v  bh_3_ = _mm256_unpacklo_pd(bf0_3_, _b_3_);
    dd_v  bl_3_ = _mm256_unpackhi_pd(bf0_3_, _b_3_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_3_  = ah_3_ * bh_3_;
    dd_v t_3_3_  = _mm256_fmsub_pd(ah_3_, bh_3_, s_3_3_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_3_ = al_3_ * bl_3_;
    dd_v  tl1_3_ = _mm256_fmadd_pd(ah_3_, bl_3_, tl0_3_);
    dd_v  cl2_3_ = _mm256_fmadd_pd(al_3_, bh_3_, tl1_3_);
    dd_v  cl3_3_ = t_3_3_ + cl2_3_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_3_ = s_3_3_ + cl3_3_;
    dd_v z_4_3_ = s_4_3_ - s_3_3_;
    dd_v t_4_3_ = cl3_3_ - z_4_3_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_3_ = _mm256_unpacklo_pd(s_4_3_, t_4_3_);
    __m256d _r_up_2_3_ = _mm256_unpackhi_pd(s_4_3_, t_4_3_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_3_  = ah_3_ * (-bh_3_);
    dd_v t_5_3_  = _mm256_fmsub_pd(ah_3_, -bh_3_, s_5_3_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_3_ = al_3_ * (-bl_3_);
    dd_v  tl1_2_3_ = _mm256_fmadd_pd(ah_3_, -bl_3_, tl0_2_3_);
    dd_v  cl2_2_3_ = _mm256_fmadd_pd(al_3_, -bh_3_, tl1_2_3_);
    dd_v  cl3_2_3_ = t_5_3_ + cl2_2_3_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_3_ = s_5_3_ + cl3_2_3_;
    dd_v z_6_3_ = s_6_3_ - s_5_3_;
    dd_v t_6_3_ = cl3_2_3_ - z_6_3_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_3_ = _mm256_unpacklo_pd(s_6_3_, t_6_3_);
    __m256d _r_lo_2_3_ = _mm256_unpackhi_pd(s_6_3_, t_6_3_);

    /* Create -inf vector */

    dd_v mask1_7_3_ = _mm256_cmp_pd(_r_up_1_3_, _r_up_2_3_, _CMP_GE_OQ);
    dd_v mask2_7_3_ = _mm256_cmp_pd(_r_up_1_3_, _r_up_2_3_, _CMP_LE_OQ);

    mask1_7_3_ = _mm256_unpacklo_pd(mask1_7_3_, mask1_7_3_);
    mask2_7_3_ = _mm256_unpacklo_pd(mask2_7_3_, mask2_7_3_);

    dd_v _a_7_3_ = _mm256_blendv_pd(minf, _r_up_1_3_, mask1_7_3_);
    dd_v _b_7_3_ = _mm256_blendv_pd(minf, _r_up_2_3_, mask2_7_3_);

    dd_I r_up_3_ = _mm256_max_pd(_a_7_3_, _b_7_3_);

    dd_v mask1_8_3_ = _mm256_cmp_pd(_r_lo_1_3_, _r_lo_2_3_, _CMP_GE_OQ);
    dd_v mask2_8_3_ = _mm256_cmp_pd(_r_lo_1_3_, _r_lo_2_3_, _CMP_LE_OQ);

    mask1_8_3_ = _mm256_unpacklo_pd(mask1_8_3_, mask1_8_3_);
    mask2_8_3_ = _mm256_unpacklo_pd(mask2_8_3_, mask2_8_3_);

    dd_v _a_8_3_ = _mm256_blendv_pd(minf, _r_lo_1_3_, mask1_8_3_);
    dd_v _b_8_3_ = _mm256_blendv_pd(minf, _r_lo_2_3_, mask2_8_3_);

    dd_I r_lo_3_ = _mm256_max_pd(_a_8_3_, _b_8_3_);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_3_ = _mm256_permute2f128_pd(r_lo_3_, r_up_3_, 0b00100000);
    dd_I c2_3_ = _mm256_permute2f128_pd(r_lo_3_, r_up_3_, 0b00110001);

    dd_v mask1_9_3_ = _mm256_cmp_pd(c1_3_, c2_3_, _CMP_GE_OQ);
    dd_v mask2_9_3_ = _mm256_cmp_pd(c1_3_, c2_3_, _CMP_LE_OQ);

    mask1_9_3_ = _mm256_unpacklo_pd(mask1_9_3_, mask1_9_3_);
    mask2_9_3_ = _mm256_unpacklo_pd(mask2_9_3_, mask2_9_3_);

    dd_v _a_9_3_ = _mm256_blendv_pd(minf, c1_3_, mask1_9_3_);
    dd_v _b_9_3_ = _mm256_blendv_pd(minf, c2_3_, mask2_9_3_);

    dst.f[0] = _mm256_max_pd(_a_9_0_, _b_9_0_);
    dst.f[1] = _mm256_max_pd(_a_9_1_, _b_9_1_);
    dst.f[2] = _mm256_max_pd(_a_9_2_, _b_9_2_);
    dst.f[3] = _mm256_max_pd(_a_9_3_, _b_9_3_);

    return dst;
}


static inline __attribute__((always_inline)) ddi_4 _igen_dd_interleaved_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dd_I af0_0 = a.f[0];
    dd_I af0_1 = a.f[1];
    dd_I af0_2 = a.f[2];
    dd_I af0_3 = a.f[3];

    dd_I bf0_0 = b.f[0];
    dd_I bf0_1 = b.f[1];
    dd_I bf0_2 = b.f[2];
    dd_I bf0_3 = b.f[3];

    dd_I _b_0 = -_mm256_permute4x64_pd(bf0_0, 0b01001110);
    dd_I _b_1 = -_mm256_permute4x64_pd(bf0_1, 0b01001110);
    dd_I _b_2 = -_mm256_permute4x64_pd(bf0_2, 0b01001110);
    dd_I _b_3 = -_mm256_permute4x64_pd(bf0_3, 0b01001110);

    dd_v  ah_0 = _mm256_unpacklo_pd(af0_0, af0_0);
    dd_v  ah_1 = _mm256_unpacklo_pd(af0_1, af0_1);
    dd_v  ah_2 = _mm256_unpacklo_pd(af0_2, af0_2);
    dd_v  ah_3 = _mm256_unpacklo_pd(af0_3, af0_3);

    dd_v  al_0 = _mm256_unpackhi_pd(af0_0, af0_0);
    dd_v  al_1 = _mm256_unpackhi_pd(af0_1, af0_1);
    dd_v  al_2 = _mm256_unpackhi_pd(af0_2, af0_2);
    dd_v  al_3 = _mm256_unpackhi_pd(af0_3, af0_3);

    dd_v  bh_0 = _mm256_unpacklo_pd(bf0_0, _b_0);
    dd_v  bh_1 = _mm256_unpacklo_pd(bf0_1, _b_1);
    dd_v  bh_2 = _mm256_unpacklo_pd(bf0_2, _b_2);
    dd_v  bh_3 = _mm256_unpacklo_pd(bf0_3, _b_3);

    dd_v  bl_0 = _mm256_unpackhi_pd(bf0_0, _b_0);
    dd_v  bl_1 = _mm256_unpackhi_pd(bf0_1, _b_1);
    dd_v  bl_2 = _mm256_unpackhi_pd(bf0_2, _b_2);
    dd_v  bl_3 = _mm256_unpackhi_pd(bf0_3, _b_3);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_0  = ah_0 * bh_0;
    dd_v s_3_1  = ah_1 * bh_1;
    dd_v s_3_2  = ah_2 * bh_2;
    dd_v s_3_3  = ah_3 * bh_3;

    dd_v t_3_0  = _mm256_fmsub_pd(ah_0, bh_0, s_3_0);
    dd_v t_3_1  = _mm256_fmsub_pd(ah_1, bh_1, s_3_1);
    dd_v t_3_2  = _mm256_fmsub_pd(ah_2, bh_2, s_3_2);
    dd_v t_3_3  = _mm256_fmsub_pd(ah_3, bh_3, s_3_3);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_0 = al_0 * bl_0;
    dd_v  tl0_1 = al_1 * bl_1;
    dd_v  tl0_2 = al_2 * bl_2;
    dd_v  tl0_3 = al_3 * bl_3;

    dd_v  tl1_0 = _mm256_fmadd_pd(ah_0, bl_0, tl0_0);
    dd_v  tl1_1 = _mm256_fmadd_pd(ah_1, bl_1, tl0_1);
    dd_v  tl1_2 = _mm256_fmadd_pd(ah_2, bl_2, tl0_2);
    dd_v  tl1_3 = _mm256_fmadd_pd(ah_3, bl_3, tl0_3);

    dd_v  cl2_0 = _mm256_fmadd_pd(al_0, bh_0, tl1_0);
    dd_v  cl2_1 = _mm256_fmadd_pd(al_1, bh_1, tl1_1);
    dd_v  cl2_2 = _mm256_fmadd_pd(al_2, bh_2, tl1_2);
    dd_v  cl2_3 = _mm256_fmadd_pd(al_3, bh_3, tl1_3);

    dd_v  cl3_0 = t_3_0 + cl2_0;
    dd_v  cl3_1 = t_3_1 + cl2_1;
    dd_v  cl3_2 = t_3_2 + cl2_2;
    dd_v  cl3_3 = t_3_3 + cl2_3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_0 = s_3_0 + cl3_0;
    dd_v s_4_1 = s_3_1 + cl3_1;
    dd_v s_4_2 = s_3_2 + cl3_2;
    dd_v s_4_3 = s_3_3 + cl3_3;

    dd_v z_4_0 = s_4_0 - s_3_0;
    dd_v z_4_1 = s_4_1 - s_3_1;
    dd_v z_4_2 = s_4_2 - s_3_2;
    dd_v z_4_3 = s_4_3 - s_3_3;

    dd_v t_4_0 = cl3_0 - z_4_0;
    dd_v t_4_1 = cl3_1 - z_4_1;
    dd_v t_4_2 = cl3_2 - z_4_2;
    dd_v t_4_3 = cl3_3 - z_4_3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_0 = _mm256_unpacklo_pd(s_4_0, t_4_0);
    __m256d _r_up_1_1 = _mm256_unpacklo_pd(s_4_1, t_4_1);
    __m256d _r_up_1_2 = _mm256_unpacklo_pd(s_4_2, t_4_2);
    __m256d _r_up_1_3 = _mm256_unpacklo_pd(s_4_3, t_4_3);

    __m256d _r_up_2_0 = _mm256_unpackhi_pd(s_4_0, t_4_0);
    __m256d _r_up_2_1 = _mm256_unpackhi_pd(s_4_1, t_4_1);
    __m256d _r_up_2_2 = _mm256_unpackhi_pd(s_4_2, t_4_2);
    __m256d _r_up_2_3 = _mm256_unpackhi_pd(s_4_3, t_4_3);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_0  = ah_0 * (-bh_0);
    dd_v s_5_1  = ah_1 * (-bh_1);
    dd_v s_5_2  = ah_2 * (-bh_2);
    dd_v s_5_3  = ah_3 * (-bh_3);

    dd_v t_5_0  = _mm256_fmsub_pd(ah_0, -bh_0, s_5_0);
    dd_v t_5_1  = _mm256_fmsub_pd(ah_1, -bh_1, s_5_1);
    dd_v t_5_2  = _mm256_fmsub_pd(ah_2, -bh_2, s_5_2);
    dd_v t_5_3  = _mm256_fmsub_pd(ah_3, -bh_3, s_5_3);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_0 = al_0 * (-bl_0);
    dd_v  tl0_2_1 = al_1 * (-bl_1);
    dd_v  tl0_2_2 = al_2 * (-bl_2);
    dd_v  tl0_2_3 = al_3 * (-bl_3);

    dd_v  tl1_2_0 = _mm256_fmadd_pd(ah_0, -bl_0, tl0_2_0);
    dd_v  tl1_2_1 = _mm256_fmadd_pd(ah_1, -bl_1, tl0_2_1);
    dd_v  tl1_2_2 = _mm256_fmadd_pd(ah_2, -bl_2, tl0_2_2);
    dd_v  tl1_2_3 = _mm256_fmadd_pd(ah_3, -bl_3, tl0_2_3);

    dd_v  cl2_2_0 = _mm256_fmadd_pd(al_0, -bh_0, tl1_2_0);
    dd_v  cl2_2_1 = _mm256_fmadd_pd(al_1, -bh_1, tl1_2_1);
    dd_v  cl2_2_2 = _mm256_fmadd_pd(al_2, -bh_2, tl1_2_2);
    dd_v  cl2_2_3 = _mm256_fmadd_pd(al_3, -bh_3, tl1_2_3);

    dd_v  cl3_2_0 = t_5_0 + cl2_2_0;
    dd_v  cl3_2_1 = t_5_1 + cl2_2_1;
    dd_v  cl3_2_2 = t_5_2 + cl2_2_2;
    dd_v  cl3_2_3 = t_5_3 + cl2_2_3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_0 = s_5_0 + cl3_2_0;
    dd_v s_6_1 = s_5_1 + cl3_2_1;
    dd_v s_6_2 = s_5_2 + cl3_2_2;
    dd_v s_6_3 = s_5_3 + cl3_2_3;

    dd_v z_6_0 = s_6_0 - s_5_0;
    dd_v z_6_1 = s_6_1 - s_5_1;
    dd_v z_6_2 = s_6_2 - s_5_2;
    dd_v z_6_3 = s_6_3 - s_5_3;

    dd_v t_6_0 = cl3_2_0 - z_6_0;
    dd_v t_6_1 = cl3_2_1 - z_6_1;
    dd_v t_6_2 = cl3_2_2 - z_6_2;
    dd_v t_6_3 = cl3_2_3 - z_6_3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_0 = _mm256_unpacklo_pd(s_6_0, t_6_0);
    __m256d _r_lo_1_1 = _mm256_unpacklo_pd(s_6_1, t_6_1);
    __m256d _r_lo_1_2 = _mm256_unpacklo_pd(s_6_2, t_6_2);
    __m256d _r_lo_1_3 = _mm256_unpacklo_pd(s_6_3, t_6_3);

    __m256d _r_lo_2_0 = _mm256_unpackhi_pd(s_6_0, t_6_0);
    __m256d _r_lo_2_1 = _mm256_unpackhi_pd(s_6_1, t_6_1);
    __m256d _r_lo_2_2 = _mm256_unpackhi_pd(s_6_2, t_6_2);
    __m256d _r_lo_2_3 = _mm256_unpackhi_pd(s_6_3, t_6_3);

    /* Create -inf vector */
    dd_v minf = _mm256_set1_pd(-1.0/0.0);

    dd_v mask1_7_0 = _mm256_cmp_pd(_r_up_1_0, _r_up_2_0, _CMP_GE_OQ);
    dd_v mask1_7_1 = _mm256_cmp_pd(_r_up_1_1, _r_up_2_1, _CMP_GE_OQ);
    dd_v mask1_7_2 = _mm256_cmp_pd(_r_up_1_2, _r_up_2_2, _CMP_GE_OQ);
    dd_v mask1_7_3 = _mm256_cmp_pd(_r_up_1_3, _r_up_2_3, _CMP_GE_OQ);

    dd_v mask2_7_0 = _mm256_cmp_pd(_r_up_1_0, _r_up_2_0, _CMP_LE_OQ);
    dd_v mask2_7_1 = _mm256_cmp_pd(_r_up_1_1, _r_up_2_1, _CMP_LE_OQ);
    dd_v mask2_7_2 = _mm256_cmp_pd(_r_up_1_2, _r_up_2_2, _CMP_LE_OQ);
    dd_v mask2_7_3 = _mm256_cmp_pd(_r_up_1_3, _r_up_2_3, _CMP_LE_OQ);

    mask1_7_0 = _mm256_unpacklo_pd(mask1_7_0, mask1_7_0);
    mask1_7_1 = _mm256_unpacklo_pd(mask1_7_1, mask1_7_1);
    mask1_7_2 = _mm256_unpacklo_pd(mask1_7_2, mask1_7_2);
    mask1_7_3 = _mm256_unpacklo_pd(mask1_7_3, mask1_7_3);

    mask2_7_0 = _mm256_unpacklo_pd(mask2_7_0, mask2_7_0);
    mask2_7_1 = _mm256_unpacklo_pd(mask2_7_1, mask2_7_1);
    mask2_7_2 = _mm256_unpacklo_pd(mask2_7_2, mask2_7_2);
    mask2_7_3 = _mm256_unpacklo_pd(mask2_7_3, mask2_7_3);

    dd_v _a_7_0 = _mm256_blendv_pd(minf, _r_up_1_0, mask1_7_0);
    dd_v _a_7_1 = _mm256_blendv_pd(minf, _r_up_1_1, mask1_7_1);
    dd_v _a_7_2 = _mm256_blendv_pd(minf, _r_up_1_2, mask1_7_2);
    dd_v _a_7_3 = _mm256_blendv_pd(minf, _r_up_1_3, mask1_7_3);

    dd_v _b_7_0 = _mm256_blendv_pd(minf, _r_up_2_0, mask2_7_0);
    dd_v _b_7_1 = _mm256_blendv_pd(minf, _r_up_2_1, mask2_7_1);
    dd_v _b_7_2 = _mm256_blendv_pd(minf, _r_up_2_2, mask2_7_2);
    dd_v _b_7_3 = _mm256_blendv_pd(minf, _r_up_2_3, mask2_7_3);

    dd_I r_up_0 = _mm256_max_pd(_a_7_0, _b_7_0);
    dd_I r_up_1 = _mm256_max_pd(_a_7_1, _b_7_1);
    dd_I r_up_2 = _mm256_max_pd(_a_7_2, _b_7_2);
    dd_I r_up_3 = _mm256_max_pd(_a_7_3, _b_7_3);

    dd_v mask1_8_0 = _mm256_cmp_pd(_r_lo_1_0, _r_lo_2_0, _CMP_GE_OQ);
    dd_v mask1_8_1 = _mm256_cmp_pd(_r_lo_1_1, _r_lo_2_1, _CMP_GE_OQ);
    dd_v mask1_8_2 = _mm256_cmp_pd(_r_lo_1_2, _r_lo_2_2, _CMP_GE_OQ);
    dd_v mask1_8_3 = _mm256_cmp_pd(_r_lo_1_3, _r_lo_2_3, _CMP_GE_OQ);

    dd_v mask2_8_0 = _mm256_cmp_pd(_r_lo_1_0, _r_lo_2_0, _CMP_LE_OQ);
    dd_v mask2_8_1 = _mm256_cmp_pd(_r_lo_1_1, _r_lo_2_1, _CMP_LE_OQ);
    dd_v mask2_8_2 = _mm256_cmp_pd(_r_lo_1_2, _r_lo_2_2, _CMP_LE_OQ);
    dd_v mask2_8_3 = _mm256_cmp_pd(_r_lo_1_3, _r_lo_2_3, _CMP_LE_OQ);

    mask1_8_0 = _mm256_unpacklo_pd(mask1_8_0, mask1_8_0);
    mask1_8_1 = _mm256_unpacklo_pd(mask1_8_1, mask1_8_1);
    mask1_8_2 = _mm256_unpacklo_pd(mask1_8_2, mask1_8_2);
    mask1_8_3 = _mm256_unpacklo_pd(mask1_8_3, mask1_8_3);

    mask2_8_0 = _mm256_unpacklo_pd(mask2_8_0, mask2_8_0);
    mask2_8_1 = _mm256_unpacklo_pd(mask2_8_1, mask2_8_1);
    mask2_8_2 = _mm256_unpacklo_pd(mask2_8_2, mask2_8_2);
    mask2_8_3 = _mm256_unpacklo_pd(mask2_8_3, mask2_8_3);

    dd_v _a_8_0 = _mm256_blendv_pd(minf, _r_lo_1_0, mask1_8_0);
    dd_v _a_8_1 = _mm256_blendv_pd(minf, _r_lo_1_1, mask1_8_1);
    dd_v _a_8_2 = _mm256_blendv_pd(minf, _r_lo_1_2, mask1_8_2);
    dd_v _a_8_3 = _mm256_blendv_pd(minf, _r_lo_1_3, mask1_8_3);

    dd_v _b_8_0 = _mm256_blendv_pd(minf, _r_lo_2_0, mask2_8_0);
    dd_v _b_8_1 = _mm256_blendv_pd(minf, _r_lo_2_1, mask2_8_1);
    dd_v _b_8_2 = _mm256_blendv_pd(minf, _r_lo_2_2, mask2_8_2);
    dd_v _b_8_3 = _mm256_blendv_pd(minf, _r_lo_2_3, mask2_8_3);

    dd_I r_lo_0 = _mm256_max_pd(_a_8_0, _b_8_0);
    dd_I r_lo_1 = _mm256_max_pd(_a_8_1, _b_8_1);
    dd_I r_lo_2 = _mm256_max_pd(_a_8_2, _b_8_2);
    dd_I r_lo_3 = _mm256_max_pd(_a_8_3, _b_8_3);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_0 = _mm256_permute2f128_pd(r_lo_0, r_up_0, 0b00100000);
    dd_I c1_1 = _mm256_permute2f128_pd(r_lo_1, r_up_1, 0b00100000);
    dd_I c1_2 = _mm256_permute2f128_pd(r_lo_2, r_up_2, 0b00100000);
    dd_I c1_3 = _mm256_permute2f128_pd(r_lo_3, r_up_3, 0b00100000);

    dd_I c2_0 = _mm256_permute2f128_pd(r_lo_0, r_up_0, 0b00110001);
    dd_I c2_1 = _mm256_permute2f128_pd(r_lo_1, r_up_1, 0b00110001);
    dd_I c2_2 = _mm256_permute2f128_pd(r_lo_2, r_up_2, 0b00110001);
    dd_I c2_3 = _mm256_permute2f128_pd(r_lo_3, r_up_3, 0b00110001);

    dd_v mask1_9_0 = _mm256_cmp_pd(c1_0, c2_0, _CMP_GE_OQ);
    dd_v mask1_9_1 = _mm256_cmp_pd(c1_1, c2_1, _CMP_GE_OQ);
    dd_v mask1_9_2 = _mm256_cmp_pd(c1_2, c2_2, _CMP_GE_OQ);
    dd_v mask1_9_3 = _mm256_cmp_pd(c1_3, c2_3, _CMP_GE_OQ);

    dd_v mask2_9_0 = _mm256_cmp_pd(c1_0, c2_0, _CMP_LE_OQ);
    dd_v mask2_9_1 = _mm256_cmp_pd(c1_1, c2_1, _CMP_LE_OQ);
    dd_v mask2_9_2 = _mm256_cmp_pd(c1_2, c2_2, _CMP_LE_OQ);
    dd_v mask2_9_3 = _mm256_cmp_pd(c1_3, c2_3, _CMP_LE_OQ);

    mask1_9_0 = _mm256_unpacklo_pd(mask1_9_0, mask1_9_0);
    mask1_9_1 = _mm256_unpacklo_pd(mask1_9_1, mask1_9_1);
    mask1_9_2 = _mm256_unpacklo_pd(mask1_9_2, mask1_9_2);
    mask1_9_3 = _mm256_unpacklo_pd(mask1_9_3, mask1_9_3);

    mask2_9_0 = _mm256_unpacklo_pd(mask2_9_0, mask2_9_0);
    mask2_9_1 = _mm256_unpacklo_pd(mask2_9_1, mask2_9_1);
    mask2_9_2 = _mm256_unpacklo_pd(mask2_9_2, mask2_9_2);
    mask2_9_3 = _mm256_unpacklo_pd(mask2_9_3, mask2_9_3);

    dd_v _a_9_0 = _mm256_blendv_pd(minf, c1_0, mask1_9_0);
    dd_v _a_9_1 = _mm256_blendv_pd(minf, c1_1, mask1_9_1);
    dd_v _a_9_2 = _mm256_blendv_pd(minf, c1_2, mask1_9_2);
    dd_v _a_9_3 = _mm256_blendv_pd(minf, c1_3, mask1_9_3);

    dd_v _b_9_0 = _mm256_blendv_pd(minf, c2_0, mask2_9_0);
    dd_v _b_9_1 = _mm256_blendv_pd(minf, c2_1, mask2_9_1);
    dd_v _b_9_2 = _mm256_blendv_pd(minf, c2_2, mask2_9_2);
    dd_v _b_9_3 = _mm256_blendv_pd(minf, c2_3, mask2_9_3);

    dst.f[0] = _mm256_max_pd(_a_9_0, _b_9_0);
    dst.f[1] = _mm256_max_pd(_a_9_1, _b_9_1);
    dst.f[2] = _mm256_max_pd(_a_9_2, _b_9_2);
    dst.f[3] = _mm256_max_pd(_a_9_3, _b_9_3);

    return dst;
}

static inline __attribute__((always_inline)) ddi_4 _transposed_mul(dd_I a_0, dd_I a_1, dd_I a_2, dd_I a_3, dd_I b_0, dd_I b_1, dd_I b_2, dd_I b_3) {
    __m256d neg_b_0 = -b_0;
    __m256d neg_b_1 = -b_1;
    __m256d neg_b_2 = -b_2;
    __m256d neg_b_3 = -b_3;

    __m256d s_3_0 = a_0 * b_0;
    __m256d s_3_1 = a_0 * neg_b_2;
    __m256d s_3_2 = a_2 * b_2;
    __m256d s_3_3 = a_2 * neg_b_0;

    __m256d t_3_0 = _mm256_fmsub_pd(a_0, b_0, s_3_0);
    __m256d t_3_1 = _mm256_fmsub_pd(a_0, neg_b_2, s_3_1);
    __m256d t_3_2 = _mm256_fmsub_pd(a_2, b_2, s_3_2);
    __m256d t_3_3 = _mm256_fmsub_pd(a_2, neg_b_0, s_3_3);

    __m256d tl0_0 = a_1 * b_1;
    __m256d tl0_1 = a_1 * neg_b_3;
    __m256d tl0_2 = a_3 * b_3;
    __m256d tl0_3 = a_3 * neg_b_1;

    __m256d tl1_0 = _mm256_fmadd_pd(a_0, b_1, tl0_0);
    __m256d tl1_1 = _mm256_fmadd_pd(a_0, neg_b_3, tl0_1);
    __m256d tl1_2 = _mm256_fmadd_pd(a_2, b_3, tl0_2);
    __m256d tl1_3 = _mm256_fmadd_pd(a_2, neg_b_1, tl0_3);

    __m256d cl2_0 = _mm256_fmadd_pd(a_1, b_0, tl1_0);
    __m256d cl2_1 = _mm256_fmadd_pd(a_1, neg_b_2, tl1_1);
    __m256d cl2_2 = _mm256_fmadd_pd(a_3, b_2, tl1_2);
    __m256d cl2_3 = _mm256_fmadd_pd(a_3, neg_b_0, tl1_3);

    __m256d cl3_0 = t_3_0 + cl2_0;
    __m256d cl3_1 = t_3_1 + cl2_1;
    __m256d cl3_2 = t_3_2 + cl2_2;
    __m256d cl3_3 = t_3_3 + cl2_3;

    __m256d s_4_0 = s_3_0 + cl3_0;
    __m256d s_4_1 = s_3_1 + cl3_1;
    __m256d s_4_2 = s_3_2 + cl3_2;
    __m256d s_4_3 = s_3_3 + cl3_3;

    __m256d z_4_0 = s_4_0 - s_3_0;
    __m256d z_4_1 = s_4_1 - s_3_1;
    __m256d z_4_2 = s_4_2 - s_3_2;
    __m256d z_4_3 = s_4_3 - s_3_3;

    __m256d t_4_0 = cl3_0 - z_4_0;
    __m256d t_4_1 = cl3_1 - z_4_1;
    __m256d t_4_2 = cl3_2 - z_4_2;
    __m256d t_4_3 = cl3_3 - z_4_3;

    __m256d s_5_0 = a_0 * neg_b_0;
    __m256d s_5_1 = a_0 * b_2;
    __m256d s_5_2 = a_2 * neg_b_2;
    __m256d s_5_3 = a_2 * b_0;

    __m256d t_5_0 = _mm256_fmsub_pd(a_0, neg_b_0, s_5_0);
    __m256d t_5_1 = _mm256_fmsub_pd(a_0, b_2, s_5_1);
    __m256d t_5_2 = _mm256_fmsub_pd(a_2, neg_b_2, s_5_2);
    __m256d t_5_3 = _mm256_fmsub_pd(a_2, b_0, s_5_3);

    __m256d tl0_2_0 = a_1 * neg_b_1;
    __m256d tl0_2_1 = a_1 * b_3;
    __m256d tl0_2_2 = a_3 * neg_b_3;
    __m256d tl0_2_3 = a_3 * b_1;

    __m256d tl1_2_0 = _mm256_fmadd_pd(a_0, neg_b_1, tl0_2_0);
    __m256d tl1_2_1 = _mm256_fmadd_pd(a_0, b_3, tl0_2_1);
    __m256d tl1_2_2 = _mm256_fmadd_pd(a_2, neg_b_3, tl0_2_2);
    __m256d tl1_2_3 = _mm256_fmadd_pd(a_2, b_1, tl0_2_3);

    __m256d cl2_2_0 = _mm256_fmadd_pd(a_1, neg_b_0, tl1_2_0);
    __m256d cl2_2_1 = _mm256_fmadd_pd(a_1, b_2, tl1_2_1);
    __m256d cl2_2_2 = _mm256_fmadd_pd(a_3, neg_b_2, tl1_2_2);
    __m256d cl2_2_3 = _mm256_fmadd_pd(a_3, b_0, tl1_2_3);

    __m256d cl3_2_0 = t_5_0 + cl2_2_0;
    __m256d cl3_2_1 = t_5_1 + cl2_2_1;
    __m256d cl3_2_2 = t_5_2 + cl2_2_2;
    __m256d cl3_2_3 = t_5_3 + cl2_2_3;

    __m256d s_6_0 = s_5_0 + cl3_2_0;
    __m256d s_6_1 = s_5_1 + cl3_2_1;
    __m256d s_6_2 = s_5_2 + cl3_2_2;
    __m256d s_6_3 = s_5_3 + cl3_2_3;

    __m256d z_6_0 = s_6_0 - s_5_0;
    __m256d z_6_1 = s_6_1 - s_5_1;
    __m256d z_6_2 = s_6_2 - s_5_2;
    __m256d z_6_3 = s_6_3 - s_5_3;

    __m256d t_6_0 = cl3_2_0 - z_6_0;
    __m256d t_6_1 = cl3_2_1 - z_6_1;
    __m256d t_6_2 = cl3_2_2 - z_6_2;
    __m256d t_6_3 = cl3_2_3 - z_6_3;

    __m256d minf = _mm256_set1_pd(-1.0/0.0);

    __m256d mask17_01 = _mm256_cmp_pd(s_4_0, s_4_1, _CMP_GE_OQ);
    __m256d mask17_23 = _mm256_cmp_pd(s_4_2, s_4_3, _CMP_GE_OQ);
    __m256d mask27_01 = _mm256_cmp_pd(s_4_0, s_4_1, _CMP_LE_OQ);
    __m256d mask27_23 = _mm256_cmp_pd(s_4_2, s_4_3, _CMP_LE_OQ);

    __m256d a7_0 = _mm256_blendv_pd(minf, s_4_0, mask17_01);
    __m256d a7_1 = _mm256_blendv_pd(minf, t_4_0, mask17_01);
    __m256d a7_2 = _mm256_blendv_pd(minf, s_4_2, mask17_23);
    __m256d a7_3 = _mm256_blendv_pd(minf, t_4_2, mask17_23);

    __m256d b7_0 = _mm256_blendv_pd(minf, s_4_1, mask27_01);
    __m256d b7_1 = _mm256_blendv_pd(minf, t_4_1, mask27_01);
    __m256d b7_2 = _mm256_blendv_pd(minf, s_4_3, mask27_23);
    __m256d b7_3 = _mm256_blendv_pd(minf, t_4_3, mask27_23);

    __m256d rup_0 = _mm256_max_pd(a7_0, b7_0);
    __m256d rup_1 = _mm256_max_pd(a7_1, b7_1);
    __m256d rup_2 = _mm256_max_pd(a7_2, b7_2);
    __m256d rup_3 = _mm256_max_pd(a7_3, b7_3);

    __m256d mask18_01 = _mm256_cmp_pd(s_6_0, s_6_1, _CMP_GE_OQ);
    __m256d mask18_23 = _mm256_cmp_pd(s_6_2, s_6_3, _CMP_GE_OQ);
    __m256d mask28_01 = _mm256_cmp_pd(s_6_0, s_6_1, _CMP_LE_OQ);
    __m256d mask28_23 = _mm256_cmp_pd(s_6_2, s_6_3, _CMP_LE_OQ);

    __m256d a8_0 = _mm256_blendv_pd(minf, s_6_0, mask18_01);
    __m256d a8_1 = _mm256_blendv_pd(minf, t_6_0, mask18_01);
    __m256d a8_2 = _mm256_blendv_pd(minf, s_6_2, mask18_23);
    __m256d a8_3 = _mm256_blendv_pd(minf, t_6_2, mask18_23);

    __m256d b8_0 = _mm256_blendv_pd(minf, s_6_1, mask28_01);
    __m256d b8_1 = _mm256_blendv_pd(minf, t_6_1, mask28_01);
    __m256d b8_2 = _mm256_blendv_pd(minf, s_6_3, mask28_23);
    __m256d b8_3 = _mm256_blendv_pd(minf, t_6_3, mask28_23);

    __m256d rlo_0 = _mm256_max_pd(a8_0, b8_0);
    __m256d rlo_1 = _mm256_max_pd(a8_1, b8_1);
    __m256d rlo_2 = _mm256_max_pd(a8_2, b8_2);
    __m256d rlo_3 = _mm256_max_pd(a8_3, b8_3);

    __m256d mask19_01 = _mm256_cmp_pd(rlo_0, rlo_2, _CMP_GE_OQ);
    __m256d mask19_23 = _mm256_cmp_pd(rup_0, rup_2, _CMP_GE_OQ);
    __m256d mask29_01 = _mm256_cmp_pd(rlo_0, rlo_2, _CMP_LE_OQ);
    __m256d mask29_23 = _mm256_cmp_pd(rup_0, rup_2, _CMP_LE_OQ);

    __m256d a9_0 = _mm256_blendv_pd(minf, rlo_0, mask19_01);
    __m256d a9_1 = _mm256_blendv_pd(minf, rlo_1, mask19_01);
    __m256d a9_2 = _mm256_blendv_pd(minf, rup_0, mask19_23);
    __m256d a9_3 = _mm256_blendv_pd(minf, rup_1, mask19_23);

    __m256d b9_0 = _mm256_blendv_pd(minf, rlo_2, mask29_01);
    __m256d b9_1 = _mm256_blendv_pd(minf, rlo_3, mask29_01);
    __m256d b9_2 = _mm256_blendv_pd(minf, rup_2, mask29_23);
    __m256d b9_3 = _mm256_blendv_pd(minf, rup_3, mask29_23);

    __m256d res_0 = _mm256_max_pd(a9_0, b9_0);
    __m256d res_1 = _mm256_max_pd(a9_1, b9_1);
    __m256d res_2 = _mm256_max_pd(a9_2, b9_2);
    __m256d res_3 = _mm256_max_pd(a9_3, b9_3);

    return (ddi_4) {.f = {res_0, res_1, res_2, res_3}};
}

static inline __attribute__((always_inline)) ddi_4 _igen_dd_transposed_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    ddi_4 trans_a = _vec_transpose(a);
    ddi_4 trans_b = _vec_transpose(b);
    __m256d a_0 = trans_a.f[0];
    __m256d a_1 = trans_a.f[1];
    __m256d a_2 = trans_a.f[2];
    __m256d a_3 = trans_a.f[3];
    __m256d b_0 = trans_b.f[0];
    __m256d b_1 = trans_b.f[1];
    __m256d b_2 = trans_b.f[2];
    __m256d b_3 = trans_b.f[3];

    ddi_4 res = _transposed_mul(a_0, a_1, a_2, a_3, b_0, b_1, b_2, b_3);
    dst = _vec_transpose(res);
    return dst;
}

typedef struct {
    double h;
    double l;
} dd;

static inline __attribute__((always_inline)) bool dd_gt(dd a, dd b) {
    if(a.h > b.h) return true;
    if(a.h < b.h) return false;
    return a.l > b.l;
}

static inline __attribute__((always_inline)) bool dd_gt_0(dd a) {
    if(a.h > 0) return true;
    if(a.h < 0) return false;
    return a.l > 0;
}

static inline __attribute__((always_inline)) dd dd_mult(dd a, dd b) {
    double ch = a.h * b.h;
    double cl1 = fma(a.h, b.h, -ch);
    double tl0 = a.l * b.l;
    double tl1 = fma(a.h, b.l, tl0);
    double cl2 = fma(a.l, b.h, tl1);
    double cl3 = cl1 + cl2;

    double s = ch + cl3;
    double z = s - ch;
    double t = cl3 - z;
    return (dd) {.h = s, .l = t};
}

static inline __attribute__((always_inline)) dd minus(dd a) {
    return (dd) {.h = -a.h, .l = -a.l};
}

static inline __attribute__((always_inline)) dd_I mul_case_dist(u_ddi a0, u_ddi b0) {
    dd a0l = {.h = a0.lh, .l = a0.ll};
    dd a0u = {.h = a0.uh, .l = a0.ul};
    dd b0l = {.h = b0.lh, .l = b0.ll};
    dd b0u = {.h = b0.uh, .l = b0.ul};

    dd r0l;
    dd r0u;

    if(dd_gt_0(a0l)) {
        if(dd_gt_0(a0u)) {
            if(dd_gt_0(b0l)) {
                if(dd_gt_0(b0u)) {
                    dd t1, t2;
                    t1 = dd_mult(a0l, b0u);
                    t2 = dd_mult(a0u, b0l);
                    r0l = (dd_gt(t1, t2)) ? t1 : t2;
                    t1 = dd_mult(a0l, b0l);
                    t2 = dd_mult(a0u, b0u);
                    r0u = (dd_gt(t1, t2)) ? t1 : t2;
                }
                else {
                    r0l = dd_mult(a0u, b0l);
                    r0u = dd_mult(a0l, b0l);
                }
            }
            else {
                if(dd_gt_0(b0u)) {
                    r0l = dd_mult(a0l, b0u);
                    r0u = dd_mult(a0u, b0u);
                }
                else {
                    r0l = {.h = 0, .l = 0};
                    r0u = {.h = 0, .l = 0};
                }
            }
        }
        else {
            if(dd_gt_0(b0l)) {
                if(dd_gt_0(b0u)) {
                    r0l = dd_mult(a0l, b0u);
                    r0u = dd_mult(a0l, b0l);
                }
                else {
                    r0l = minus(dd_mult(a0u, b0u));
                    r0u = dd_mult(a0l, b0l);
                }
            }
            else {
                if(dd_gt_0(b0u)) {
                    r0l = dd_mult(a0l, b0u);
                    r0u = minus(dd_mult(a0u, b0l));
                }
                else {
                    r0l = {.h = 0, .l = 0};
                    r0u = {.h = 0, .l = 0};
                }
            }
        }
    }
    else {
        if(dd_gt_0(a0u)) {
            if(dd_gt_0(b0l)) {
                if(dd_gt_0(b0u)) {
                    r0l = dd_mult(a0u, b0l);
                    r0u = dd_mult(a0u, b0u);
                }
                else {
                    r0l = dd_mult(a0u, b0l);
                    r0u = minus(dd_mult(a0l, b0u));
                }
            }
            else {
                if(dd_gt_0(b0u)) {
                    r0l = minus(dd_mult(a0l, b0l));
                    r0u = dd_mult(a0u, b0u);
                }
                else {
                    r0l = {.h = 0, .l = 0};
                    r0u = {.h = 0, .l = 0};
                }
            }
        }
        else {
            r0l = {.h = 0, .l = 0};
            r0u = {.h = 0, .l = 0};
        }
    }

    u_ddi r0;
    r0.ll = r0l.l;
    r0.lh = r0l.h;
    r0.ul = r0u.l;
    r0.uh = r0u.h;

    return r0.v;
}

static inline __attribute__((always_inline)) ddi_4 _igen_dd_case_distinction_no_simd_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = mul_case_dist({.v = a.f[0]}, {.v = b.f[0]});
    dst.f[1] = mul_case_dist({.v = a.f[1]}, {.v = b.f[1]});
    dst.f[2] = mul_case_dist({.v = a.f[2]}, {.v = b.f[2]});
    dst.f[3] = mul_case_dist({.v = a.f[3]}, {.v = b.f[3]});

    return dst;
}


//#define _igen_dd_op_mm256_mul_pd _igen_dd_case_distinction_no_simd_mm256_mul_pd
#define _igen_dd_op_mm256_mul_pd _igen_dd_transposed_mm256_mul_pd
//#define _igen_dd_op_mm256_mul_pd _igen_dd_fb_mm256_mul_pd
