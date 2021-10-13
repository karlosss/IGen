#pragma once
#include <math.h>
#define bool int
#define true 1
#define false 0

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

static inline __attribute__((always_inline)) ddi_4 _igen_dd_op_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    ddi_4 trans_a = _vec_transpose_ddi4(a);
    ddi_4 trans_b = _vec_transpose_ddi4(b);
    __m256d a_0 = trans_a.f[0];
    __m256d a_1 = trans_a.f[1];
    __m256d a_2 = trans_a.f[2];
    __m256d a_3 = trans_a.f[3];
    __m256d b_0 = trans_b.f[0];
    __m256d b_1 = trans_b.f[1];
    __m256d b_2 = trans_b.f[2];
    __m256d b_3 = trans_b.f[3];

    ddi_4 res = _transposed_mul(a_0, a_1, a_2, a_3, b_0, b_1, b_2, b_3);
    dst = _vec_transpose_ddi4(res);
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
                    r0l.h = 0;
                    r0l.l = 0;
                    r0u.h = 0;
                    r0u.l = 0;
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
                    r0l.h = 0;
                    r0l.l = 0;
                    r0u.h = 0;
                    r0u.l = 0;
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
                    r0l.h = 0;
                    r0l.l = 0;
                    r0u.h = 0;
                    r0u.l = 0;
                }
            }
        }
        else {
            r0l.h = 0;
            r0l.l = 0;
            r0u.h = 0;
            r0u.l = 0;
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

    u_ddi af0;
    u_ddi af1;
    u_ddi af2;
    u_ddi af3;
    u_ddi bf0;
    u_ddi bf1;
    u_ddi bf2;
    u_ddi bf3;
    af0.v = a.f[0];
    af1.v = a.f[1];
    af2.v = a.f[2];
    af3.v = a.f[3];
    bf0.v = b.f[0];
    bf1.v = b.f[1];
    bf2.v = b.f[2];
    bf3.v = b.f[3];

    dst.f[0] = mul_case_dist(af0, bf0);
    dst.f[1] = mul_case_dist(af1, bf1);
    dst.f[2] = mul_case_dist(af2, bf2);
    dst.f[3] = mul_case_dist(af3, bf3);

    return dst;
}
