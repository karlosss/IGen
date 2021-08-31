#pragma once

static ddi_4 _igen_dd_no_loop_mm256_div_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_div_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_div_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_div_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_div_dd(a.f[3], b.f[3]);

    return dst;
}

static ddi_4 _igen_dd_inline_fn_mm256_div_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dd_I one = _ia_set_dd(-1.0, -0.0, -1.0, -0.0);
    dd_I inf = _ia_set_dd(INFINITY, -0.0, INFINITY, 0.0);

    u_ddi _b0 = { .v = b.f[0]};
    int bNoZero0 = (_b0.uh < 0.0 || (_b0.uh == 0.0 && _b0.ul <  0.0)) || (_b0.lh < 0.0 || (_b0.lh == 0.0 && _b0.ll <  0.0));

    if (bNoZero0) {
        dd_I inv_b0 = _vec_div_dd(one, b.f[0]);
        inv_b0 = _mm256_permute4x64_pd(inv_b0, 0b01001110);
        dst.f[0] = _ia_mul_dd(a.f[0], inv_b0);
    }
    else {
        dst.f[0] = inf;
    }

    u_ddi _b1 = { .v = b.f[1]};
    int bNoZero1 = (_b1.uh < 0.0 || (_b1.uh == 0.0 && _b1.ul <  0.0)) || (_b1.lh < 0.0 || (_b1.lh == 0.0 && _b1.ll <  0.0));

    if (bNoZero1) {
        dd_I inv_b1 = _vec_div_dd(one, b.f[1]);
        inv_b1 = _mm256_permute4x64_pd(inv_b1, 0b01001110);
        dst.f[1] = _ia_mul_dd(a.f[1], inv_b1);
    }
    else {
        dst.f[1] = inf;
    }

    u_ddi _b2 = { .v = b.f[2]};
    int bNoZero2 = (_b2.uh < 0.0 || (_b2.uh == 0.0 && _b2.ul <  0.0)) || (_b2.lh < 0.0 || (_b2.lh == 0.0 && _b2.ll <  0.0));

    if (bNoZero2) {
        dd_I inv_b2 = _vec_div_dd(one, b.f[2]);
        inv_b2 = _mm256_permute4x64_pd(inv_b2, 0b01001110);
        dst.f[2] = _ia_mul_dd(a.f[2], inv_b2);
    }
    else {
        dst.f[2] = inf;
    }

    u_ddi _b3 = { .v = b.f[3]};
    int bNoZero3 = (_b3.uh < 0.0 || (_b3.uh == 0.0 && _b3.ul <  0.0)) || (_b3.lh < 0.0 || (_b3.lh == 0.0 && _b3.ll <  0.0));

    if (bNoZero3) {
        dd_I inv_b3 = _vec_div_dd(one, b.f[3]);
        inv_b3 = _mm256_permute4x64_pd(inv_b3, 0b01001110);
        dst.f[3] = _ia_mul_dd(a.f[3], inv_b3);
    }
    else {
        dst.f[3] = inf;
    }

    return dst;
}


static ddi_4 _igen_dd_transposed_mm256_div_pd(ddi_4 a, ddi_4 b) {
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

    dd_I inf = _ia_set_dd(INFINITY, -0.0, INFINITY, 0.0);
    __m256d zero_t = _mm256_setzero_pd();
    __m256d one_t = _mm256_set1_pd(1.0);

    dd_v div_0 = 1.0 / b_0;
    dd_v div_2 = 1.0 / b_2;

    dd_v r0_0 = _mm256_fnmadd_pd(b_0, div_0, one_t);
    dd_v r0_1 = _mm256_fnmadd_pd(b_1, div_0, zero_t);
    dd_v r0_2 = _mm256_fnmadd_pd(b_2, div_2, one_t);
    dd_v r0_3 = _mm256_fnmadd_pd(b_3, div_2, zero_t);

    dd_v s01_0 = r0_0 + r0_1;
    dd_v s01_2 = r0_2 + r0_3;

    dd_v z0_0 = s01_0 - r0_0;
    dd_v z0_2 = s01_2 - r0_2;

    dd_v t0_0 = r0_1 - z0_0;
    dd_v t0_2 = r0_3 - z0_2;

    dd_v s03_0  = s01_0 * div_0;
    dd_v s03_2  = s01_2 * div_2;

    dd_v t03_0  = _mm256_fmsub_pd(s01_0, div_0, s03_0);
    dd_v t03_2  = _mm256_fmsub_pd(s01_2, div_2, s03_2);

    dd_v cl202_0   = _mm256_fmadd_pd(t0_0, div_0, t03_0);
    dd_v cl202_2   = _mm256_fmadd_pd(t0_2, div_2, t03_2);

    dd_v s04_0 = s03_0 + cl202_0;
    dd_v s04_2 = s03_2 + cl202_2;

    dd_v z04_0 = s04_0 - s03_0;
    dd_v z04_2 = s04_2 - s03_2;

    dd_v t04_0 = cl202_0 - z04_0;
    dd_v t04_2 = cl202_2 - z04_2;

    dd_v s06_0  = s04_0 + div_0;
    dd_v s06_2  = s04_2 + div_2;

    dd_v a_06_0 = s06_0 - div_0;
    dd_v a_06_2 = s06_2 - div_2;

    dd_v b_06_0 = s06_0 - a_06_0;
    dd_v b_06_2 = s06_2 - a_06_2;

    dd_v da06_0 = s04_0 - a_06_0;
    dd_v da06_2 = s04_2 - a_06_2;

    dd_v db06_0 = div_0 - b_06_0;
    dd_v db06_2 = div_2 - b_06_2;

    dd_v t06_0  = da06_0 + db06_0;
    dd_v t06_2  = da06_2 + db06_2;

    dd_v  v05_0  = t04_0 + t06_0;
    dd_v  v05_2  = t04_2 + t06_2;

    dd_v s07_0 = s06_0 + v05_0;
    dd_v s07_2 = s06_2 + v05_2;

    dd_v z07_0 = s07_0 - s06_0;
    dd_v z07_2 = s07_2 - s06_2;

    dd_v t07_0 = v05_0 - z07_0;
    dd_v t07_2 = v05_2 - z07_2;

    dd_v  cl308_0 = -t07_0;
    dd_v  cl308_2 = -t07_2;

    dd_v s010_0 = cl308_0 - s07_0;
    dd_v s010_2 = cl308_2 - s07_2;

    dd_v z010_0 = s010_0 + s07_0;
    dd_v z010_2 = s010_2 + s07_2;

    dd_v t010_0 = cl308_0 - z010_0;
    dd_v t010_2 = cl308_2 - z010_2;

    ddi_4 res = _transposed_mul(a_0, a_1, a_2, a_3, s010_2, t010_2, s010_0, t010_0);
    dst = _vec_transpose_ddi4(res);

    u_ddi _b0 = { .v = b.f[0]};
    u_ddi _b1 = { .v = b.f[1]};
    u_ddi _b2 = { .v = b.f[2]};
    u_ddi _b3 = { .v = b.f[3]};
    bool bNoZero0 = (_b0.uh < 0.0 || (_b0.uh == 0.0 && _b0.ul <  0.0)) || (_b0.lh < 0.0 || (_b0.lh == 0.0 && _b0.ll <  0.0));
    bool bNoZero1 = (_b1.uh < 0.0 || (_b1.uh == 0.0 && _b1.ul <  0.0)) || (_b1.lh < 0.0 || (_b1.lh == 0.0 && _b1.ll <  0.0));
    bool bNoZero2 = (_b2.uh < 0.0 || (_b2.uh == 0.0 && _b2.ul <  0.0)) || (_b2.lh < 0.0 || (_b2.lh == 0.0 && _b2.ll <  0.0));
    bool bNoZero3 = (_b3.uh < 0.0 || (_b3.uh == 0.0 && _b3.ul <  0.0)) || (_b3.lh < 0.0 || (_b3.lh == 0.0 && _b3.ll <  0.0));
    if(!bNoZero0) dst.f[0] = inf;
    if(!bNoZero1) dst.f[1] = inf;
    if(!bNoZero2) dst.f[2] = inf;
    if(!bNoZero3) dst.f[3] = inf;

    return dst;
}


static ddi_4 _igen_dd_transposed_avx_cond_mm256_div_pd(ddi_4 a, ddi_4 b) {
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

    __m256d inf_t = _mm256_set1_pd(INFINITY);
    __m256d zero_t = _mm256_setzero_pd();
    __m256d neg_zero_t = _mm256_set1_pd(-0.0);
    __m256d one_t = _mm256_set1_pd(1.0);

    dd_v div_0 = 1.0 / b_0;
    dd_v div_2 = 1.0 / b_2;

    dd_v r0_0 = _mm256_fnmadd_pd(b_0, div_0, one_t);
    dd_v r0_1 = _mm256_fnmadd_pd(b_1, div_0, zero_t);
    dd_v r0_2 = _mm256_fnmadd_pd(b_2, div_2, one_t);
    dd_v r0_3 = _mm256_fnmadd_pd(b_3, div_2, zero_t);

    dd_v s01_0 = r0_0 + r0_1;
    dd_v s01_2 = r0_2 + r0_3;

    dd_v z0_0 = s01_0 - r0_0;
    dd_v z0_2 = s01_2 - r0_2;

    dd_v t0_0 = r0_1 - z0_0;
    dd_v t0_2 = r0_3 - z0_2;

    dd_v s03_0  = s01_0 * div_0;
    dd_v s03_2  = s01_2 * div_2;

    dd_v t03_0  = _mm256_fmsub_pd(s01_0, div_0, s03_0);
    dd_v t03_2  = _mm256_fmsub_pd(s01_2, div_2, s03_2);

    dd_v cl202_0   = _mm256_fmadd_pd(t0_0, div_0, t03_0);
    dd_v cl202_2   = _mm256_fmadd_pd(t0_2, div_2, t03_2);

    dd_v s04_0 = s03_0 + cl202_0;
    dd_v s04_2 = s03_2 + cl202_2;

    dd_v z04_0 = s04_0 - s03_0;
    dd_v z04_2 = s04_2 - s03_2;

    dd_v t04_0 = cl202_0 - z04_0;
    dd_v t04_2 = cl202_2 - z04_2;

    dd_v s06_0  = s04_0 + div_0;
    dd_v s06_2  = s04_2 + div_2;

    dd_v a_06_0 = s06_0 - div_0;
    dd_v a_06_2 = s06_2 - div_2;

    dd_v b_06_0 = s06_0 - a_06_0;
    dd_v b_06_2 = s06_2 - a_06_2;

    dd_v da06_0 = s04_0 - a_06_0;
    dd_v da06_2 = s04_2 - a_06_2;

    dd_v db06_0 = div_0 - b_06_0;
    dd_v db06_2 = div_2 - b_06_2;

    dd_v t06_0  = da06_0 + db06_0;
    dd_v t06_2  = da06_2 + db06_2;

    dd_v  v05_0  = t04_0 + t06_0;
    dd_v  v05_2  = t04_2 + t06_2;

    dd_v s07_0 = s06_0 + v05_0;
    dd_v s07_2 = s06_2 + v05_2;

    dd_v z07_0 = s07_0 - s06_0;
    dd_v z07_2 = s07_2 - s06_2;

    dd_v t07_0 = v05_0 - z07_0;
    dd_v t07_2 = v05_2 - z07_2;

    dd_v  cl308_0 = -t07_0;
    dd_v  cl308_2 = -t07_2;

    dd_v s010_0 = cl308_0 - s07_0;
    dd_v s010_2 = cl308_2 - s07_2;

    dd_v z010_0 = s010_0 + s07_0;
    dd_v z010_2 = s010_2 + s07_2;

    dd_v t010_0 = cl308_0 - z010_0;
    dd_v t010_2 = cl308_2 - z010_2;

    ddi_4 res = _transposed_mul(a_0, a_1, a_2, a_3, s010_2, t010_2, s010_0, t010_0);
    dd_v res_0 = res.f[0];
    dd_v res_1 = res.f[1];
    dd_v res_2 = res.f[2];
    dd_v res_3 = res.f[3];

    __m256d b0uh_lt_0 = _mm256_cmp_pd(b_2, zero_t, _CMP_LT_OQ);
    __m256d b0uh_eq_0 = _mm256_cmp_pd(b_2, zero_t, _CMP_EQ_OQ);
    __m256d b0ul_lt_0 = _mm256_cmp_pd(b_3, zero_t, _CMP_LT_OQ);
    __m256d b0lh_lt_0 = _mm256_cmp_pd(b_0, zero_t, _CMP_LT_OQ);
    __m256d b0lh_eq_0 = _mm256_cmp_pd(b_0, zero_t, _CMP_EQ_OQ);
    __m256d b0ll_lt_0 = _mm256_cmp_pd(b_1, zero_t, _CMP_LT_OQ);
    __m256d and0 = _mm256_and_pd(b0uh_eq_0, b0ul_lt_0);
    __m256d and1 = _mm256_and_pd(b0lh_eq_0, b0ll_lt_0);
    __m256d or0 = _mm256_or_pd(b0uh_lt_0, and0);
    __m256d or1 = _mm256_or_pd(b0lh_lt_0, and1);
    __m256d b_no_zero = _mm256_or_pd(or0, or1);

    dd_v b_res_0 = _mm256_blendv_pd(inf_t, res_0, b_no_zero);
    dd_v b_res_1 = _mm256_blendv_pd(neg_zero_t, res_1, b_no_zero);
    dd_v b_res_2 = _mm256_blendv_pd(inf_t, res_2, b_no_zero);
    dd_v b_res_3 = _mm256_blendv_pd(zero_t, res_3, b_no_zero);

    dst = _vec_transpose_m256d(b_res_0, b_res_1, b_res_2, b_res_3);

    return dst;
}

//#define _igen_dd_op_mm256_div_pd _igen_dd_transposed_avx_cond_mm256_div_pd
//#define _igen_dd_op_mm256_div_pd _igen_dd_fb_mm256_div_pd
#define _igen_dd_op_mm256_div_pd _igen_dd_inline_fn_mm256_div_pd
