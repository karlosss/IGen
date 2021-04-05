#pragma once

#include <immintrin.h>

#include "igen_immintrin.h"
#include "igen_dd_immintrin_types.h"
#include "igen_dd_immintrin_internal.h"
#include "igen_dd_lib.h"
#include "igen_dd_math.h"

static ddi_4 _igen_dd_op_mm256_add_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

// vec_add_dd

//    dd2_v s_t  = twoSum(a, b);
//    dd_v  th   = _mm256_permute_pd(s_t.h, 0b0101);
//    dd_v  tl   = _mm256_permute_pd(s_t.l, 0b0101);
//    dd_v  c    = s_t.l + th;
//    dd2_v v    = fastTwoSum(s_t.h, c);
//    dd_v  w    = tl + v.l;
//    dd2_v z    = fastTwoSum(v.h, w);
//    dd_v  z_hl = _mm256_unpacklo_pd(z.h, z.l);
//    return z_hl;

//twosum(a,b)

//#ifdef ROUND_TO_NEAREST
//    int _fround = fegetround();
//    fesetround(FE_TONEAREST);
//#endif
//
//    dd_v s  = a + b;
//    dd_v a_ = s - b;
//    dd_v b_ = s - a_;
//    dd_v da = a - a_;
//    dd_v db = b - b_;
//    dd_v t  = da + db;
//
//#ifdef ROUND_TO_NEAREST
//    fesetround(_fround);
//#endif
//
//    dd2_v r;
//    r.h = s;
//    r.l = t;
//    return r;

// fast two sum(a, b)

//#ifdef ROUND_TO_NEAREST
//    int _fround = fegetround();
//    fesetround(FE_TONEAREST);
//#endif
//
//    dd_v f2s = a + b;
//    dd_v f2z = f2s - a;
//    dd_v f2t = b - f2z;
//
//#ifdef ROUND_TO_NEAREST
//    fesetround(_fround);
//#endif
//
//    dd2_v f2r;
//    f2r.h = f2s;
//    f2r.l = f2t;
//    return f2r;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif
    dd_v af0 = a.f[0];
    dd_v af1 = a.f[1];
    dd_v af2 = a.f[2];
    dd_v af3 = a.f[3];

    dd_v bf0 = b.f[0];
    dd_v bf1 = b.f[1];
    dd_v bf2 = b.f[2];
    dd_v bf3 = b.f[3];

    dd_v s0  = af0 + bf0;
    dd_v s1  = af1 + bf1;
    dd_v s2  = af2 + bf2;
    dd_v s3  = af3 + bf3;

    dd_v a_0 = s0 - bf0;
    dd_v a_1 = s1 - bf1;
    dd_v a_2 = s2 - bf2;
    dd_v a_3 = s3 - bf3;

    dd_v b_0 = s0 - a_0;
    dd_v b_1 = s1 - a_1;
    dd_v b_2 = s2 - a_2;
    dd_v b_3 = s3 - a_3;

    dd_v da0 = af0 - a_0;
    dd_v da1 = af1 - a_1;
    dd_v da2 = af2 - a_2;
    dd_v da3 = af3 - a_3;

    dd_v db0 = bf0 - b_0;
    dd_v db1 = bf1 - b_1;
    dd_v db2 = bf2 - b_2;
    dd_v db3 = bf3 - b_3;

    dd_v t0  = da0 + db0;
    dd_v t1  = da1 + db1;
    dd_v t2  = da2 + db2;
    dd_v t3  = da3 + db3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  th0   = _mm256_permute_pd(s0, 0b0101);
    dd_v  th1   = _mm256_permute_pd(s1, 0b0101);
    dd_v  th2   = _mm256_permute_pd(s2, 0b0101);
    dd_v  th3   = _mm256_permute_pd(s3, 0b0101);

    dd_v  tl0   = _mm256_permute_pd(t0, 0b0101);
    dd_v  tl1   = _mm256_permute_pd(t1, 0b0101);
    dd_v  tl2   = _mm256_permute_pd(t2, 0b0101);
    dd_v  tl3   = _mm256_permute_pd(t3, 0b0101);

    dd_v  c0    = t0 + th0;
    dd_v  c1    = t1 + th1;
    dd_v  c2    = t2 + th2;
    dd_v  c3    = t3 + th3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f2s0 = s0 + c0;
    dd_v f2s1 = s1 + c1;
    dd_v f2s2 = s2 + c2;
    dd_v f2s3 = s3 + c3;

    dd_v f2z0 = f2s0 - s0;
    dd_v f2z1 = f2s1 - s1;
    dd_v f2z2 = f2s2 - s2;
    dd_v f2z3 = f2s3 - s3;

    dd_v f2t0 = c0 - f2z0;
    dd_v f2t1 = c1 - f2z1;
    dd_v f2t2 = c2 - f2z2;
    dd_v f2t3 = c3 - f2z3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  w0    = tl0 + f2t0;
    dd_v  w1    = tl1 + f2t1;
    dd_v  w2    = tl2 + f2t2;
    dd_v  w3    = tl3 + f2t3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f3s0 = f2s0 + w0;
    dd_v f3s1 = f2s1 + w1;
    dd_v f3s2 = f2s2 + w2;
    dd_v f3s3 = f2s3 + w3;

    dd_v f3z0 = f3s0 - f2s0;
    dd_v f3z1 = f3s1 - f2s1;
    dd_v f3z2 = f3s2 - f2s2;
    dd_v f3z3 = f3s3 - f2s3;

    dd_v f3t0 = w0 - f3z0;
    dd_v f3t1 = w1 - f3z1;
    dd_v f3t2 = w2 - f3z2;
    dd_v f3t3 = w3 - f3z3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dst.f[0] = _mm256_unpacklo_pd(f3s0, f3t0);
    dst.f[1] = _mm256_unpacklo_pd(f3s1, f3t1);
    dst.f[2] = _mm256_unpacklo_pd(f3s2, f3t2);
    dst.f[3] = _mm256_unpacklo_pd(f3s3, f3t3);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_mul_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_mul_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_mul_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_mul_dd(a.f[3], b.f[3]);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_fmadd_pd(ddi_4 a, ddi_4 b, ddi_4 c) {
    ddi_4 dst;
    ddi_4 t1 = _igen_dd_op_mm256_mul_pd(a, b);
    dst = _igen_dd_op_mm256_add_pd(t1, c);
    return dst;
}

static ddi_4 _igen_dd_op_mm256_hadd_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_add_dd(a.f[1], a.f[0]);
    dst.f[2] = _ia_add_dd(a.f[3], a.f[2]);
    dst.f[1] = _ia_add_dd(b.f[1], b.f[0]);
    dst.f[3] = _ia_add_dd(b.f[3], b.f[2]);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_div_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_div_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_div_dd(a.f[0], b.f[0]);
    dst.f[2] = _ia_div_dd(a.f[0], b.f[0]);
    dst.f[3] = _ia_div_dd(a.f[0], b.f[0]);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_sub_pd(ddi_4 a, ddi_4 b) {
    ddi_4 _b;
    _b.f[0] = _mm256_permute4x64_pd(b.f[0], 0b01001110);
    _b.f[1] = _mm256_permute4x64_pd(b.f[1], 0b01001110);
    _b.f[2] = _mm256_permute4x64_pd(b.f[2], 0b01001110);
    _b.f[3] = _mm256_permute4x64_pd(b.f[3], 0b01001110);

    return _igen_dd_op_mm256_add_pd(a, _b);
}

static ddi_4 _igen_dd_op_mm256_permute2f128_pd(ddi_4 a, ddi_4 b, int imm8) {
    ddi_4 dst;

    if (imm8 & 8) {
        dst.f[0] = zero_ddi;
        dst.f[1] = zero_ddi;
    }
    else {
        switch (imm8 & 3) {
            case 0:
                dst.f[0] = a.f[0];
                dst.f[1] = a.f[1];
                break;
            case 1:
                dst.f[0] = a.f[2];
                dst.f[1] = a.f[3];
                break;
            case 2:
                dst.f[0] = b.f[0];
                dst.f[1] = b.f[1];
                break;
            case 3:
                dst.f[0] = b.f[2];
                dst.f[1] = b.f[3];
                break;
        }
    }

    if (imm8 & 128) {
        dst.f[2] = zero_ddi;
        dst.f[3] = zero_ddi;
    }
    else {
        switch (imm8 & 48) {
            case 0:
                dst.f[2] = a.f[0];
                dst.f[3] = a.f[1];
                break;
            case 16:
                dst.f[2] = a.f[2];
                dst.f[3] = a.f[3];
                break;
            case 32:
                dst.f[2] = b.f[0];
                dst.f[3] = b.f[1];
                break;
            case 48:
                dst.f[2] = b.f[2];
                dst.f[3] = b.f[3];
                break;
        }
    }

    return dst;
}

static ddi_4 _igen_dd_op_mm256_blend_pd(ddi_4 a, ddi_4 b, int imm8) {
    ddi_4 dst;

    dst.f[0] = (imm8 & 1) == 0 ? a.f[0] : b.f[0];
    dst.f[1] = (imm8 & 2) == 0 ? a.f[1] : b.f[1];
    dst.f[2] = (imm8 & 4) == 0 ? a.f[2] : b.f[2];
    dst.f[3] = (imm8 & 8) == 0 ? a.f[3] : b.f[3];

    return dst;
}

static ddi_4 _igen_dd_op_mm256_shuffle_pd(ddi_4 a, ddi_4 b, int imm8) {
    ddi_4 dst;
    dst.f[0] = a.f[imm8 & 1];
    dst.f[2] = a.f[2+((imm8 & 4) > 0)];
    dst.f[1] = b.f[(imm8 & 2) > 0];
    dst.f[3] = b.f[2+((imm8 & 8) > 0)];
    return dst;
}

static ddi_4 _igen_dd_op_mm256_set_pd(dd_I e3, dd_I e2, dd_I e1, dd_I e0) {
    ddi_4 dst;

    _mm256_store_pd((double*) dst.f, e0);
    _mm256_store_pd((double*) (dst.f+1), e1);
    _mm256_store_pd((double*) (dst.f+2), e2);
    _mm256_store_pd((double*) (dst.f+3), e3);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_set1_pd(dd_I a) {
    ddi_4 dst;

    _mm256_store_pd((double*) dst.f, a);
    _mm256_store_pd((double*) (dst.f+1), a);
    _mm256_store_pd((double*) (dst.f+2), a);
    _mm256_store_pd((double*) (dst.f+3), a);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_setzero_pd() {
    ddi_4 dst;
    dst.f[0] = _ia_set_pointed_dd(0.0,0.0);
    dst.f[1] = _ia_set_pointed_dd(0.0,0.0);
    dst.f[2] = _ia_set_pointed_dd(0.0,0.0);
    dst.f[3] = _ia_set_pointed_dd(0.0,0.0);
    return dst;
}

static ddi_4 _igen_dd_op_mm256_castpd128_pd256(ddi_2 a) {
    ddi_4 dst;
    dst.f[0] = a.f[0];
    dst.f[1] = a.f[1];
    return dst;
}

static ddi_2 _igen_dd_op_mm256_castpd256_pd128(ddi_4 a) {
    ddi_2 dst;
    dst.f[0] = a.f[0];
    dst.f[1] = a.f[1];
    return dst;
}

static ddi_4 _igen_dd_op_mm256_loadu_pd(const dd_I *mem_addr) {
    ddi_4 dst;

    dd_I a1 = _mm256_load_pd((const double*) mem_addr);
    dd_I a2 = _mm256_load_pd((const double*) (mem_addr+1));
    dd_I a3 = _mm256_load_pd((const double*) (mem_addr+2));
    dd_I a4 = _mm256_load_pd((const double*) (mem_addr+3));

    _mm256_store_pd((double*) dst.f, a1);
    _mm256_store_pd((double*) (dst.f+1), a2);
    _mm256_store_pd((double*) (dst.f+2), a3);
    _mm256_store_pd((double*) (dst.f+3), a4);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_load_pd(const dd_I *mem_addr) {
    return _igen_dd_op_mm256_loadu_pd(mem_addr);
}

static void _igen_dd_op_mm256_storeu_pd(dd_I *mem_addr, ddi_4 a) {
    dd_I a1 = _mm256_load_pd((const double*) a.f);
    dd_I a2 = _mm256_load_pd((const double*) (a.f+1));
    dd_I a3 = _mm256_load_pd((const double*) (a.f+2));
    dd_I a4 = _mm256_load_pd((const double*) (a.f+3));

    _mm256_store_pd((double*) mem_addr, a1);
    _mm256_store_pd((double*) (mem_addr+1), a2);
    _mm256_store_pd((double*) (mem_addr+2), a3);
    _mm256_store_pd((double*) (mem_addr+3), a4);
}

static ddi_4 _igen_dd_op_mm256_broadcast_sd(const dd_I *mem_addr) {
    ddi_4 dst;

    dd_I val = _mm256_load_pd( (const double*) mem_addr );

    _mm256_store_pd( (double*) dst.f, val);
    _mm256_store_pd( (double*) (dst.f+1), val);
    _mm256_store_pd( (double*) (dst.f+2), val);
    _mm256_store_pd( (double*) (dst.f+3), val);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_unpackhi_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dd_I a1 = _mm256_load_pd( (const double*) (a.f+1) );
    dd_I a2 = _mm256_load_pd( (const double*) (a.f+3) );
    dd_I b1 = _mm256_load_pd( (const double*) (b.f+1) );
    dd_I b2 = _mm256_load_pd( (const double*) (b.f+3) );

    _mm256_store_pd( (double*) dst.f, a1);
    _mm256_store_pd( (double*) (dst.f+2), a2);
    _mm256_store_pd( (double*) (dst.f+1), b1);
    _mm256_store_pd( (double*) (dst.f+3), b2);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_unpacklo_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dd_I a1 = _mm256_load_pd( (const double*) a.f );
    dd_I a2 = _mm256_load_pd( (const double*) (a.f+2) );
    dd_I b1 = _mm256_load_pd( (const double*) b.f );
    dd_I b2 = _mm256_load_pd( (const double*) (b.f+2) );

    _mm256_store_pd( (double*) dst.f, a1);
    _mm256_store_pd( (double*) (dst.f+2), a2);
    _mm256_store_pd( (double*) (dst.f+1), b1);
    _mm256_store_pd( (double*) (dst.f+3), b2);

    return dst;
}