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


static inline ddi_4 _igen_dd_all_inline_fn_mm256_div_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dd_I one = _ia_set_dd(-1.0, -0.0, -1.0, -0.0);
    dd_I inf = _ia_set_dd(INFINITY, -0.0, INFINITY, 0.0);

    u_ddi _b0 = { .v = b.f[0]};
    int bNoZero0 = (_b0.uh < 0.0 || (_b0.uh == 0.0 && _b0.ul <  0.0)) || (_b0.lh < 0.0 || (_b0.lh == 0.0 && _b0.ll <  0.0));

    if (bNoZero0) {
        dd_v  oz0   = _mm256_set_pd(0.0, 1.0, 0.0, 1.0);
        dd_v  th0   = _mm256_permute_pd(1.0 / b.f[0], 0b0000);
        dd_v  r0    = _mm256_fnmadd_pd(b.f[0], th0, oz0);
        dd_v  rl0   = _mm256_permute_pd(r0, 0b1111);
        dd_v s01 = r0 + rl0;
        dd_v z0 = s01 - r0;
        dd_v t0 = rl0 - z0;
        dd2_v e0;
        e0.h = s01;
        e0.l = t0;
        dd_v  e_hl0 = _mm256_unpacklo_pd(e0.h, e0.l);
        dd_v s03  = e_hl0 * th0;
        dd_v t03  = _mm256_fmsub_pd(e_hl0, th0, s03);
        dd2_v c02;
        c02.h = s03;
        c02.l = t03;
        dd_v _a02    = _mm256_permute_pd(e_hl0, 0b0101);
        dd_v cl202   = _mm256_fmadd_pd(_a02, th0, c02.l);
        dd_v s04 = c02.h + cl202;
        dd_v z04 = s04 - c02.h;
        dd_v t04 = cl202 - z04;
        dd2_v z02;
        z02.h = s04;
        z02.l = t04;
        dd_v  d0 = _mm256_unpacklo_pd(z02.h, z02.l);
        dd_v s06  = d0 + th0;
        dd_v a_06 = s06 - th0;
        dd_v b_06 = s06 - a_06;
        dd_v da06 = d0 - a_06;
        dd_v db06 = th0 - b_06;
        dd_v t06  = da06 + db06;
        dd2_v s05;
        s05.h = s06;
        s05.l = t06;
        dd_v _a05  = _mm256_permute_pd(d0, 0b0101);
        dd_v  v05  = _a05 + s05.l;
        dd_v s07 = s05.h + v05;
        dd_v z07 = s07 - s05.h;
        dd_v t07 = v05 - z07;
        dd2_v z05;
        z05.h = s07;
        z05.l = t07;
        dd_v  m0 = _mm256_unpacklo_pd(z05.h, z05.l);
        dd_v s09  = one * m0;
        dd_v t09  = _mm256_fmsub_pd(one, m0, s09);
        dd2_v c08;
        c08.h = s09;
        c08.l = t09;
        dd_v  tl008 = _mm256_permute_pd(c08.h, 0b0101);
        dd_v _a08   = _mm256_permute_pd(one,   0b0101);
        dd_v _b08   = _mm256_permute_pd(m0,   0b0101);
        dd_v  tl108 = _mm256_fmadd_pd(one, _b08, tl008);
        dd_v  cl208 = _mm256_fmadd_pd(_a08,  m0, tl108);
        dd_v  cl308 = c08.l + cl208;
        dd_v s010 = c08.h + cl308;
        dd_v z010 = s010 - c08.h;
        dd_v t010 = cl308 - z010;
        dd2_v z08;
        z08.h = s010;
        z08.l = t010;
        dd_v  inv_b0 = _mm256_unpacklo_pd(z08.h, z08.l);
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