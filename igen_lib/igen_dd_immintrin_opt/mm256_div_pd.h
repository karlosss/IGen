#pragma once

static inline ddi_4 _igen_dd_no_loop_mm256_div_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_div_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_div_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_div_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_div_dd(a.f[3], b.f[3]);

    return dst;
}

static inline ddi_4 _igen_dd_inline_fn_mm256_div_pd(ddi_4 a, ddi_4 b) {
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


static void print_m256d(__m256d x) {
    double* a = (double*) &x;
    std::cout << a[3] << " " << a[2] << " " << a[1] << " " << a[0] << "\n";
}


static inline ddi_4 _igen_dd_transposed_mm256_div_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    ddi_4 trans_a = _vec_transpose(a);
    ddi_4 trans_b = _vec_transpose(b);

    __m256d a_lh = trans_a.f[0];
    __m256d a_ll = trans_a.f[1];
    __m256d a_uh = trans_a.f[2];
    __m256d a_ul = trans_a.f[3];

    __m256d b_lh = trans_b.f[0];
    __m256d b_ll = trans_b.f[1];
    __m256d b_uh = trans_b.f[2];
    __m256d b_ul = trans_b.f[3];

    dd_I one = _ia_set_dd(-1.0, -0.0, -1.0, -0.0);
    dd_I one_perm = _ia_set_dd(-0.0, -1.0, -0.0, -1.0);
    dd_I inf = _ia_set_dd(INFINITY, -0.0, INFINITY, 0.0);
    __m256d inf_t = _mm256_set1_pd(INFINITY);
    __m256d zero_t = _mm256_setzero_pd();
    __m256d neg_one_t = _mm256_set1_pd(-1.0);
    __m256d neg_zero_t = _mm256_set1_pd(-0.0);
    __m256d one_t = _mm256_set1_pd(1.0);

//    u_ddi _b0 = { .v = b.f[0]};
//    int bNoZero0 = (_b0.uh < 0.0 || (_b0.uh == 0.0 && _b0.ul <  0.0)) || (_b0.lh < 0.0 || (_b0.lh == 0.0 && _b0.ll <  0.0));

//    if (bNoZero0) {
        dd_v  oz0   = _mm256_set_pd(0.0, 1.0, 0.0, 1.0);
        dd_v  th0   = _mm256_permute_pd(1.0 / b.f[0], 0b0000);
        dd_v  r0    = _mm256_fnmadd_pd(b.f[0], th0, oz0);
        dd_v  rl0   = _mm256_permute_pd(r0, 0b1111);
        dd_v s01 = r0 + rl0;
        dd_v z0 = s01 - r0;
        dd_v t0 = rl0 - z0;
        dd_v  e_hl0 = _mm256_unpacklo_pd(s01, t0);
        dd_v s03  = e_hl0 * th0;
        dd_v t03  = _mm256_fmsub_pd(e_hl0, th0, s03);
        dd_v _a02    = _mm256_permute_pd(e_hl0, 0b0101);
        dd_v cl202   = _mm256_fmadd_pd(_a02, th0, t03);
        dd_v s04 = s03 + cl202;
        dd_v z04 = s04 - s03;
        dd_v t04 = cl202 - z04;
        dd_v  d0 = _mm256_unpacklo_pd(s04, t04);
        dd_v s06  = d0 + th0;
        dd_v a_06 = s06 - th0;
        dd_v b_06 = s06 - a_06;
        dd_v da06 = d0 - a_06;
        dd_v db06 = th0 - b_06;
        dd_v t06  = da06 + db06;
        dd_v _a05  = _mm256_permute_pd(d0, 0b0101);
        dd_v  v05  = _a05 + t06;
        dd_v s07 = s06 + v05;
        dd_v z07 = s07 - s06;
        dd_v t07 = v05 - z07;
        dd_v  m0 = _mm256_unpacklo_pd(s07, t07);
        dd_v s09  = one * m0;
        dd_v t09  = _mm256_fmsub_pd(one, m0, s09);
        dd_v  tl008 = _mm256_permute_pd(s09, 0b0101);
        dd_v _b08   = _mm256_permute_pd(m0,   0b0101);
        dd_v  tl108 = _mm256_fmadd_pd(one, _b08, tl008);
        dd_v  cl208 = _mm256_fmadd_pd(one_perm,  m0, tl108);
        dd_v  cl308 = t09 + cl208;
        dd_v s010 = s09 + cl308;
        dd_v z010 = s010 - s09;
        dd_v t010 = cl308 - z010;
        dd_v  inv_b0 = _mm256_unpacklo_pd(s010, t010);
        inv_b0 = _mm256_permute4x64_pd(inv_b0, 0b01001110);
        dst.f[0] = _ia_mul_dd(a.f[0], inv_b0);
//    }
//    else {
//        dst.f[0] = inf;
//    }

//    u_ddi _b1 = { .v = b.f[1]};
//    int bNoZero1 = (_b1.uh < 0.0 || (_b1.uh == 0.0 && _b1.ul <  0.0)) || (_b1.lh < 0.0 || (_b1.lh == 0.0 && _b1.ll <  0.0));
//
//    if (bNoZero1) {
        dd_I inv_b1 = _vec_div_dd(one, b.f[1]);
        inv_b1 = _mm256_permute4x64_pd(inv_b1, 0b01001110);
        dst.f[1] = _ia_mul_dd(a.f[1], inv_b1);
//    }
//    else {
//        dst.f[1] = inf;
//    }

//    u_ddi _b2 = { .v = b.f[2]};
//    int bNoZero2 = (_b2.uh < 0.0 || (_b2.uh == 0.0 && _b2.ul <  0.0)) || (_b2.lh < 0.0 || (_b2.lh == 0.0 && _b2.ll <  0.0));
//
//    if (bNoZero2) {
        dd_I inv_b2 = _vec_div_dd(one, b.f[2]);
        inv_b2 = _mm256_permute4x64_pd(inv_b2, 0b01001110);
        dst.f[2] = _ia_mul_dd(a.f[2], inv_b2);
//    }
//    else {
//        dst.f[2] = inf;
//    }

//    u_ddi _b3 = { .v = b.f[3]};
//    int bNoZero3 = (_b3.uh < 0.0 || (_b3.uh == 0.0 && _b3.ul <  0.0)) || (_b3.lh < 0.0 || (_b3.lh == 0.0 && _b3.ll <  0.0));
//
//    if (bNoZero3) {
        dd_I inv_b3 = _vec_div_dd(one, b.f[3]);
        inv_b3 = _mm256_permute4x64_pd(inv_b3, 0b01001110);
        dst.f[3] = _ia_mul_dd(a.f[3], inv_b3);
//    }
//    else {
//        dst.f[3] = inf;
//    }

    return dst;
}