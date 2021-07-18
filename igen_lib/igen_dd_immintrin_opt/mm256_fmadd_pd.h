#pragma once

static inline ddi_4 _igen_dd_op_mm256_fmadd_pd(ddi_4 a, ddi_4 b, ddi_4 c) {
    ddi_4 dst;

    ddi_4 trans_a = _vec_transpose(a);
    ddi_4 trans_b = _vec_transpose(b);
    ddi_4 trans_c = _vec_transpose(c);

    dd_v a_0 = trans_a.f[0];
    dd_v a_1 = trans_a.f[1];
    dd_v a_2 = trans_a.f[2];
    dd_v a_3 = trans_a.f[3];
    dd_v b_0 = trans_b.f[0];
    dd_v b_1 = trans_b.f[1];
    dd_v b_2 = trans_b.f[2];
    dd_v b_3 = trans_b.f[3];
    dd_v c_0 = trans_c.f[0];
    dd_v c_1 = trans_c.f[1];
    dd_v c_2 = trans_c.f[2];
    dd_v c_3 = trans_c.f[3];

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

    dd_v s0_0  = res_0 + c_0;
    dd_v s0_1  = res_1 + c_1;
    dd_v s0_2  = res_2 + c_2;
    dd_v s0_3  = res_3 + c_3;

    dd_v a0_0 = s0_0 - c_0;
    dd_v a0_1 = s0_1 - c_1;
    dd_v a0_2 = s0_2 - c_2;
    dd_v a0_3 = s0_3 - c_3;

    dd_v b0_0 = s0_0 - a0_0;
    dd_v b0_1 = s0_1 - a0_1;
    dd_v b0_2 = s0_2 - a0_2;
    dd_v b0_3 = s0_3 - a0_3;

    dd_v da0_0 = res_0 - a0_0;
    dd_v da0_1 = res_1 - a0_1;
    dd_v da0_2 = res_2 - a0_2;
    dd_v da0_3 = res_3 - a0_3;

    dd_v db0_0 = c_0 - b0_0;
    dd_v db0_1 = c_1 - b0_1;
    dd_v db0_2 = c_2 - b0_2;
    dd_v db0_3 = c_3 - b0_3;

    dd_v t0_0 = da0_0 + db0_0;
    dd_v t0_1 = da0_1 + db0_1;
    dd_v t0_2 = da0_2 + db0_2;
    dd_v t0_3 = da0_3 + db0_3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

//    dd_v  c0    = t0 + th0;
    dd_v c0_0 = t0_0 + s0_1;
    dd_v c0_2 = t0_2 + s0_3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

//    dd_v f2s0 = s0 + c0;
    dd_v f2s0_0 = s0_0 + c0_0;
    dd_v f2s0_2 = s0_2 + c0_2;

//    dd_v f2z0 = f2s0 - s0;
    dd_v f2z0_0 = f2s0_0 - s0_0;
    dd_v f2z0_2 = f2s0_2 - s0_2;

//    dd_v f2t0 = c0 - f2z0;
    dd_v f2t0_0 = c0_0 - f2z0_0;
    dd_v f2t0_2 = c0_2 - f2z0_2;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

//    dd_v  w0    = tl0 + f2t0;
    dd_v  w0_0    = t0_1 + f2t0_0;
    dd_v  w0_2    = t0_3 + f2t0_2;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

//    dd_v f3s0 = f2s0 + w0;
    dd_v f3s0_0 = f2s0_0 + w0_0;
    dd_v f3s0_2 = f2s0_2 + w0_2;

//    dd_v f3z0 = f3s0 - f2s0;
    dd_v f3z0_0 = f3s0_0 - f2s0_0;
    dd_v f3z0_2 = f3s0_2 - f2s0_2;

//    dd_v f3t0 = w0 - f3z0;
    dd_v f3t0_0 = w0_0 - f3z0_0;
    dd_v f3t0_2 = w0_2 - f3z0_2;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    dst = _vec_transpose(f3s0_0, f3t0_0, f3s0_2, f3t0_2);
    return dst;
}

static inline ddi_4 _igen_dd_sep_mm256_fmadd_pd(ddi_4 a, ddi_4 b, ddi_4 c) {
    auto tmp = _igen_dd_transposed_mm256_mul_pd(a, b);
    return _igen_dd_no_unused_vals_mm256_add_pd(tmp, c);
}