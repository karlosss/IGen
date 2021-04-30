#pragma once

#include <immintrin.h>

#include "igen_immintrin.h"
#include "igen_dd_immintrin_types.h"
#include "igen_dd_immintrin_fallback.h"
#include "igen_dd_immintrin_internal.h"
#include "igen_dd_lib.h"
#include "igen_dd_math.h"

// ================ LOAD ======================

inline static ddi_4 _igen_dd_op_mm256_loadu_pd(const dd_I *mem_addr) {
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

inline static ddi_4 _igen_dd_op_mm256_load_pd(const dd_I *mem_addr) {
    return _igen_dd_op_mm256_loadu_pd(mem_addr);
}

inline static ddi_4 _igen_dd_op_mm256_maskload_pd(const dd_I *mem_addr, __m256i _mask) {
    vec256i mask;
    mask.v = _mask;
    ddi_4 dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (vecBitAccess_i(mask.i, i + 63)) {
            dst.f[i / 64] = *(mem_addr + i / 64);
        } else {
            dst.f[i / 64] = zero_ddi;
        }
    }

    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_broadcast_sd(const dd_I *mem_addr) {
    ddi_4 dst;

    dd_I val = _mm256_load_pd( (const double*) mem_addr );

    _mm256_store_pd( (double*) dst.f, val);
    _mm256_store_pd( (double*) (dst.f+1), val);
    _mm256_store_pd( (double*) (dst.f+2), val);
    _mm256_store_pd( (double*) (dst.f+3), val);

    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_broadcast_pd(ddi_2 *_mem_addr) {
    vec128d *mem_addr = (vec128d *)_mem_addr;
    vec256d dst;
    vec128d tmp;

    tmp.f[0] = mem_addr->f[0];
    tmp.f[1] = mem_addr->f[1];

    dst.f[0] = tmp.f[0];
    dst.f[1] = tmp.f[1];

    dst.f[2] = tmp.f[0];
    dst.f[3] = tmp.f[1];

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_i64gather_pd(const dd_I *base_addr, __m256i _vindex, int scale) {
    vec256i vindex;
    vindex.v = _vindex;
    vec256d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        m = j * 64;
        dst.f[i / 64] =
                *(base_addr +
                  ((base_addr + SignExtend_i(vindex.l[(m) / 64]) * scale - base_addr) /
                   8));
    }

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_set1_pd(dd_I a) {
    ddi_4 dst;

    _mm256_store_pd((double*) dst.f, a);
    _mm256_store_pd((double*) (dst.f+1), a);
    _mm256_store_pd((double*) (dst.f+2), a);
    _mm256_store_pd((double*) (dst.f+3), a);

    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_set_pd(dd_I e3, dd_I e2, dd_I e1, dd_I e0) {
    ddi_4 dst;

    _mm256_store_pd((double*) dst.f, e0);
    _mm256_store_pd((double*) (dst.f+1), e1);
    _mm256_store_pd((double*) (dst.f+2), e2);
    _mm256_store_pd((double*) (dst.f+3), e3);

    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_setr_pd(dd_I e3, dd_I e2, dd_I e1, dd_I e0) {
    ddi_4 dst;

    _mm256_store_pd((double*) dst.f, e3);
    _mm256_store_pd((double*) (dst.f+1), e2);
    _mm256_store_pd((double*) (dst.f+2), e1);
    _mm256_store_pd((double*) (dst.f+3), e0);

    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_setzero_pd() {
    ddi_4 dst;
    dst.f[0] = _ia_set_pointed_dd(0.0,0.0);
    dst.f[1] = _ia_set_pointed_dd(0.0,0.0);
    dst.f[2] = _ia_set_pointed_dd(0.0,0.0);
    dst.f[3] = _ia_set_pointed_dd(0.0,0.0);
    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_set_m128d(ddi_2 _hi, ddi_2 _lo) {
    vec128d hi;
    hi.v = _hi;
    vec128d lo;
    lo.v = _lo;
    vec256d dst;

    dst.f[0] = lo.f[0];
    dst.f[1] = lo.f[1];

    dst.f[2] = hi.f[0];
    dst.f[3] = hi.f[1];

    return dst.v;
}

// ================ STORE ======================

inline static void _igen_dd_op_mm256_storeu_pd(dd_I *mem_addr, ddi_4 a) {
    dd_I a1 = _mm256_load_pd((const double*) a.f);
    dd_I a2 = _mm256_load_pd((const double*) (a.f+1));
    dd_I a3 = _mm256_load_pd((const double*) (a.f+2));
    dd_I a4 = _mm256_load_pd((const double*) (a.f+3));

    _mm256_store_pd((double*) mem_addr, a1);
    _mm256_store_pd((double*) (mem_addr+1), a2);
    _mm256_store_pd((double*) (mem_addr+2), a3);
    _mm256_store_pd((double*) (mem_addr+3), a4);
}

inline static void _igen_dd_op_mm256_store_pd(dd_I *mem_addr, ddi_4 a) {
    _igen_dd_op_mm256_storeu_pd(mem_addr, a);
}

inline static void _igen_dd_op_mm256_maskstore_pd(dd_I *mem_addr, __m256i _mask, ddi_4 _a) {
    vec256i mask;
    mask.v = _mask;
    vec256d a;
    a.v = _a;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (vecBitAccess_i(mask.i, i + 63)) {
            *(mem_addr + i / 64) = a.f[i / 64];
        }
    }
}

inline static void _igen_dd_op_mm256_storeu2_m128d(dd_I *hiaddr, dd_I *loaddr, ddi_4 _a) {
    vec256d a;
    a.v = _a;

    *(loaddr + 0) = a.f[0];
    *(loaddr + 1) = a.f[1];

    *(hiaddr + 0) = a.f[2];
    *(hiaddr + 1) = a.f[3];
}

inline static void _igen_dd_op_mm256_stream_pd(dd_I *mem_addr, ddi_4 _a) {
    vec256d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
}

// ================ ARITHMETIC ======================

inline static ddi_4 _igen_dd_op_mm256_add_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

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

inline static ddi_4 _igen_dd_inlined_loop_mm256_add_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_add_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_add_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_add_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_add_dd(a.f[3], b.f[3]);

    return dst;
}

inline static ddi_4 _igen_dd_forloop_mm256_add_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;
    for(int i = 0; i < 4; ++i){
        dst.f[i] = _ia_add_dd(a.f[i], b.f[i]);
    }
    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_sub_pd(ddi_4 a, ddi_4 b) {
    ddi_4 _b;
    _b.f[0] = _mm256_permute4x64_pd(b.f[0], 0b01001110);
    _b.f[1] = _mm256_permute4x64_pd(b.f[1], 0b01001110);
    _b.f[2] = _mm256_permute4x64_pd(b.f[2], 0b01001110);
    _b.f[3] = _mm256_permute4x64_pd(b.f[3], 0b01001110);

    return _igen_dd_op_mm256_add_pd(a, _b);
}

inline static ddi_4 _igen_dd_op_mm256_addsub_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (j % 1 == 0) {
            dst.f[i / 64] = _ia_sub_dd(a.f[i / 64], b.f[i / 64]);
        } else {
            dst.f[i / 64] = _ia_add_dd(a.f[i / 64], b.f[i / 64]);
        }
    }

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_hadd_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_add_dd(a.f[1], a.f[0]);
    dst.f[2] = _ia_add_dd(a.f[3], a.f[2]);
    dst.f[1] = _ia_add_dd(b.f[1], b.f[0]);
    dst.f[3] = _ia_add_dd(b.f[3], b.f[2]);

    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_hsub_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    dst.f[0] = _ia_sub_dd(a.f[0], a.f[1]);
    dst.f[1] = _ia_sub_dd(b.f[0], b.f[1]);
    dst.f[2] = _ia_sub_dd(a.f[2], a.f[3]);
    dst.f[3] = _ia_sub_dd(b.f[2], b.f[3]);

    return dst.v;
}

inline static ddi_4 _igen_dd_forloop_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    for(int i = 0; i < 4; ++i) {
        dst.f[i] = _ia_mul_dd(a.f[i], b.f[i]);
    }

    return dst;
}

inline static ddi_4 _igen_dd_inlined_loop_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_mul_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_mul_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_mul_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_mul_dd(a.f[3], b.f[3]);

    return dst;
}

inline static ddi_4 _igen_dd_one_inlined_fn_mm256_mul_pd(ddi_4 a, ddi_4 b) {
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


    dst.f[1] = _ia_mul_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_mul_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_mul_dd(a.f[3], b.f[3]);

    return dst;
}

inline static ddi_4 _igen_dd_interleaved_mm256_mul_pd(ddi_4 a, ddi_4 b) {
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

inline static ddi_4 _igen_dd_transposed_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    __m256d af0 = a.f[0];
    __m256d af1 = a.f[1];
    __m256d af2 = a.f[2];
    __m256d af3 = a.f[3];

    __m256d bf0 = b.f[0];
    __m256d bf1 = b.f[1];
    __m256d bf2 = b.f[2];
    __m256d bf3 = b.f[3];

//    __m256d a_0 = af0;
//    __m256d a_1 = af1;
//    __m256d a_2 = af2;
//    __m256d a_3 = af3;
//    __m256d b_0 = bf0;
//    __m256d b_1 = bf1;
//    __m256d b_2 = bf2;
//    __m256d b_3 = bf3;

    __m256d tmpa0 = _mm256_shuffle_pd(af0, af1, 0x0);
    __m256d tmpa1 = _mm256_shuffle_pd(af0, af1, 0xF);
    __m256d tmpa2 = _mm256_shuffle_pd(af2, af3, 0x0);
    __m256d tmpa3 = _mm256_shuffle_pd(af2, af3, 0xF);

    __m256d tmpb0 = _mm256_shuffle_pd(bf0, bf1, 0x0);
    __m256d tmpb1 = _mm256_shuffle_pd(bf0, bf1, 0xF);
    __m256d tmpb2 = _mm256_shuffle_pd(bf2, bf3, 0x0);
    __m256d tmpb3 = _mm256_shuffle_pd(bf2, bf3, 0xF);

    __m256d a_0 = _mm256_permute2f128_pd(tmpa0, tmpa2, 0x20);
    __m256d a_1 = _mm256_permute2f128_pd(tmpa1, tmpa3, 0x20);
    __m256d a_2 = _mm256_permute2f128_pd(tmpa0, tmpa2, 0x31);
    __m256d a_3 = _mm256_permute2f128_pd(tmpa1, tmpa3, 0x31);

    __m256d b_0 = _mm256_permute2f128_pd(tmpb0, tmpb2, 0x20);
    __m256d b_1 = _mm256_permute2f128_pd(tmpb1, tmpb3, 0x20);
    __m256d b_2 = _mm256_permute2f128_pd(tmpb0, tmpb2, 0x31);
    __m256d b_3 = _mm256_permute2f128_pd(tmpb1, tmpb3, 0x31);

    // ===================================================================

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

    // =================================================================

    __m256d tmpres0 = _mm256_shuffle_pd(res_0, res_1, 0x0);
    __m256d tmpres1 = _mm256_shuffle_pd(res_0, res_1, 0xF);
    __m256d tmpres2 = _mm256_shuffle_pd(res_2, res_3, 0x0);
    __m256d tmpres3 = _mm256_shuffle_pd(res_2, res_3, 0xF);

    __m256d finres_0 = _mm256_permute2f128_pd(tmpres0, tmpres2, 0x20);
    __m256d finres_1 = _mm256_permute2f128_pd(tmpres1, tmpres3, 0x20);
    __m256d finres_2 = _mm256_permute2f128_pd(tmpres0, tmpres2, 0x31);
    __m256d finres_3 = _mm256_permute2f128_pd(tmpres1, tmpres3, 0x31);

    dst.f[0] = finres_0;
    dst.f[1] = finres_1;
    dst.f[2] = finres_2;
    dst.f[3] = finres_3;

//    dst.f[0] = res_0;
//    dst.f[1] = res_1;
//    dst.f[2] = res_2;
//    dst.f[3] = res_3;
    return dst;
}

#define _igen_dd_op_mm256_mul_pd _igen_dd_inlined_loop_mm256_mul_pd

inline static ddi_4 _igen_dd_no_loop_mm256_div_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_div_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_div_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_div_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_div_dd(a.f[3], b.f[3]);

    return dst;
}

#define _igen_dd_op_mm256_div_pd _igen_dd_no_loop_mm256_div_pd

inline static ddi_4 _igen_dd_op_mm256_sqrt_pd(ddi_4 a) {
    ddi_4 dst;

    dst.f[0] = _ia_sqrt_dd(a.f[0]);
    dst.f[1] = _ia_sqrt_dd(a.f[1]);
    dst.f[2] = _ia_sqrt_dd(a.f[2]);
    dst.f[3] = _ia_sqrt_dd(a.f[3]);

    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_max_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = MAX_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_min_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = MIN_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_ceil_pd(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = CEIL_d(a.f[i / 64]);
    }

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_floor_pd(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = FLOOR_d(a.f[i / 64]);
    }

    return dst.v;
}

inline static ddi_8 _igen_dd_op_mm256_dp_ps(ddi_8 _a, ddi_8 _b, int imm8) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;
    vec256s temp;
    vec256s sum;
    vec256s tmpdst;

    DP_ssi(&dst.f[0], &a.f[0], &b.f[0],
           (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)));
    DP_ssi(&dst.f[4], &a.f[4], &b.f[4],
           (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)));

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_round_pd(ddi_4 _a, int rounding) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ROUND_di(a.f[i / 64], rounding);
    }

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_fmadd_pd(ddi_4 a, ddi_4 b, ddi_4 c) {
    ddi_4 dst;
    ddi_4 t1 = _igen_dd_op_mm256_mul_pd(a, b);
    dst = _igen_dd_op_mm256_add_pd(t1, c);
    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_fmsub_pd(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d c;
    c.v = _c;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dd_I _t137 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = _ia_sub_dd(_t137, c.f[i / 64]);
    }

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_fmaddsub_pd(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d c;
    c.v = _c;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (j % 1 == 0) {
            dd_I _t130 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_sub_dd(_t130, c.f[i / 64]);
        } else {
            dd_I _t131 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_add_dd(_t131, c.f[i / 64]);
        }
    }

    return dst.v;
}

// ================ COMPARISON ======================
/*
inline static ddi_4 _igen_dd_op_mm256_cmp_pd(ddi_4 _a, ddi_4 _b, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int (*op)(dd_I, dd_I);
    int j;
    int i;

    switch ((((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1))) {
        case 0:
            op = _cmp_eq;
            break;
        case 1:
            op = _cmp_lt;
            break;
        case 2:
            op = _cmp_leq;
            break;
        case 3:
            op = _cmp_unord;
            break;
        case 4:
            op = _cmp_neq;
            break;
        case 5:
            op = _cmp_geq;
            break;
        case 6:
            op = _cmp_gt;
            break;
        case 7:
            op = _cmp_ord;
            break;
        case 8:
            op = _cmp_eq;
            break;
        case 9:
            op = _cmp_lt;
            break;
        case 10:
            op = _cmp_leq;
            break;
        case 11:
            op = _cmp_false;
            break;
        case 12:
            op = _cmp_neq;
            break;
        case 13:
            op = _cmp_geq;
            break;
        case 14:
            op = _cmp_gt;
            break;
        case 15:
            op = _cmp_true;
            break;
        case 16:
            op = _cmp_eq;
            break;
        case 17:
            op = _cmp_lt;
            break;
        case 18:
            op = _cmp_leq;
            break;
        case 19:
            op = _cmp_unord;
            break;
        case 20:
            op = _cmp_neq;
            break;
        case 21:
            op = _cmp_geq;
            break;
        case 22:
            op = _cmp_gt;
            break;
        case 23:
            op = _cmp_ord;
            break;
        case 24:
            op = _cmp_eq;
            break;
        case 25:
            op = _cmp_lt;
            break;
        case 26:
            op = _cmp_leq;
            break;
        case 27:
            op = _cmp_false;
            break;
        case 28:
            op = _cmp_neq;
            break;
        case 29:
            op = _cmp_geq;
            break;
        case 30:
            op = _cmp_gt;
            break;
        case 31:
            op = _cmp_true;
            break;
    }
    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        unsigned long _t68 = (op(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t68);
    }

    return dst.v;
}
*/
// ================ CONVERSION ======================

inline static ddi_4 _igen_dd_op_mm256_cvtepi32_pd(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        m = j * 64;
        dst.f[m / 64] = Convert_Int32_To_FP64_i(a.i[i / 32]);
    }

    return dst.v;
}

inline static ddi_8 _igen_dd_op_mm256_cvtepi32_ps(__m256i _a) {
    vec256i a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = 32 * j;
        dst.f[i / 32] = Convert_Int32_To_FP32_i(a.i[i / 32]);
    }

    return dst.v;
}

inline static __m128i _igen_dd_op_mm256_cvtpd_epi32(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.i[i / 32] = Convert_FP64_To_Int32_d(a.f[k / 64]);
    }

    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

inline static __m256i _igen_dd_op_mm256_cvtps_epi32(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256i dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = 32 * j;
        dst.i[i / 32] = Convert_FP32_To_Int32_s(a.f[i / 32]);
    }

    __m256i _ret;
    _ret = dst.v;
    return _ret;
}

inline static ddi_4 _igen_dd_op_mm256_cvtps_pd(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 64 * j;
        k = 32 * j;
        dst.f[i / 64] = Convert_FP32_To_FP64_s(a.f[k / 32]);
    }

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_cvtpd_ps(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.f[i / 32] = Convert_FP64_To_FP32_d(a.f[k / 64]);
    }

    return dst.v;
}

inline static __m128i _igen_dd_op_mm256_cvttpd_epi32(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.i[i / 32] = Convert_FP64_To_Int32_Truncate_d(a.f[k / 64]);
    }

    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

inline static dd_I _igen_dd_op_mm256_cvtsd_f64(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    dd_I dst;

    dst = a.f[0];
    return dst;
}

inline static dd_I _igen_dd_op_mm256_cvtss_f32(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    dd_I dst;

    dst = a.f[0];
    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_castpd128_pd256(ddi_2 a) {
    ddi_4 dst;
    dst.f[0] = a.f[0];
    dst.f[1] = a.f[1];
    return dst;
}

inline static ddi_2 _igen_dd_op_mm256_castpd256_pd128(ddi_4 a) {
    ddi_2 dst;
    dst.f[0] = a.f[0];
    dst.f[1] = a.f[1];
    return dst;
}

// ================ SHUFFLE ======================

inline static ddi_4 _igen_dd_op_mm256_unpackhi_pd(ddi_4 a, ddi_4 b) {
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

inline static ddi_4 _igen_dd_op_mm256_unpacklo_pd(ddi_4 a, ddi_4 b) {
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

// not supported
inline static int _igen_dd_op_mm256_movemask_pd(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    int dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (vecBitAccess_d(a.i, i + 63)) {
            dst = ((dst & ~(1 << (j))) | ((1) << (j)));
        } else {
            dst = ((dst & ~(1 << (j))) | ((0) << (j)));
        }
    }
    (dst) = ((dst) & (~(((1 << ((31) - (4) + 1)) - 1) << ((4))))) | ((0) << (4));
    int _ret;
    _ret = dst;
    return _ret;
}

inline static ddi_4 _igen_dd_op_mm256_movedup_pd(ddi_4 a) {
    ddi_4 dst;

    dd_I a0 = _mm256_load_pd( (const double*) a.f );
    dd_I a2 = _mm256_load_pd( (const double*) (a.f+2) );

    _mm256_store_pd( (double*) dst.f, a0);
    _mm256_store_pd( (double*) (dst.f+1), a0);
    _mm256_store_pd( (double*) (dst.f+2), a2);
    _mm256_store_pd( (double*) (dst.f+3), a2);

    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_blend_pd(ddi_4 a, ddi_4 b, int imm8) {
    ddi_4 dst;

    dst.f[0] = (imm8 & 1) == 0 ? a.f[0] : b.f[0];
    dst.f[1] = (imm8 & 2) == 0 ? a.f[1] : b.f[1];
    dst.f[2] = (imm8 & 4) == 0 ? a.f[2] : b.f[2];
    dst.f[3] = (imm8 & 8) == 0 ? a.f[3] : b.f[3];

    return dst;
}

// not supported
inline static ddi_4 _igen_dd_op_mm256_blendv_pd(ddi_4 _a, ddi_4 _b, ddi_4 _mask) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d mask;
    mask.v = _mask;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (vecBitAccess_d(mask.i, i + 63)) {
            dst.f[i / 64] = b.f[i / 64];
        } else {
            dst.f[i / 64] = a.f[i / 64];
        }
    }

    return dst.v;
}

// TODO benchmark fn
inline static ddi_4 _igen_dd_op_mm256_insertf128_pd(ddi_4 a, ddi_2 b, int imm8) {
    ddi_4 dst;

    dst.f[0] = imm8 & 1 ? a.f[0] : b.f[0];
    dst.f[1] = imm8 & 1 ? a.f[1] : b.f[1];
    dst.f[2] = imm8 & 1 ? b.f[0] : a.f[2];
    dst.f[3] = imm8 & 1 ? b.f[1] : a.f[3];

    return dst;
}

// TODO benchmark fn
inline static ddi_2 _igen_dd_op_mm256_extractf128_pd(ddi_4 a, int imm8) {
    ddi_2 dst;

    dst.f[0] = imm8 & 1 ? a.f[2] : a.f[0];
    dst.f[1] = imm8 & 1 ? a.f[3] : a.f[1];

    return dst;
}

// TODO benchmark fn
inline static ddi_4 _igen_dd_op_mm256_shuffle_pd(ddi_4 a, ddi_4 b, int imm8) {
    ddi_4 dst;
    dst.f[0] = a.f[imm8 & 1];
    dst.f[2] = a.f[2+((imm8 & 4) > 0)];
    dst.f[1] = b.f[(imm8 & 2) > 0];
    dst.f[3] = b.f[2+((imm8 & 8) > 0)];
    return dst;
}

inline static ddi_4 _igen_dd_op_mm256_permute_pd(ddi_4 _a, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d dst;

    if (((imm8 >> 0) & 1) == 0) {
        dst.f[0] = a.f[0];
    }
    if (((imm8 >> 0) & 1) == 1) {
        dst.f[0] = a.f[1];
    }
    if (((imm8 >> 1) & 1) == 0) {
        dst.f[1] = a.f[0];
    }
    if (((imm8 >> 1) & 1) == 1) {
        dst.f[1] = a.f[1];
    }
    if (((imm8 >> 2) & 1) == 0) {
        dst.f[2] = a.f[2];
    }
    if (((imm8 >> 2) & 1) == 1) {
        dst.f[2] = a.f[3];
    }
    if (((imm8 >> 3) & 1) == 0) {
        dst.f[3] = a.f[2];
    }
    if (((imm8 >> 3) & 1) == 1) {
        dst.f[3] = a.f[3];
    }

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_permute4x64_pd(ddi_4 _a, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d dst;

    dst.f[0] = SELECT4_di(&a.f[0], imm8 & 3);
    dst.f[1] = SELECT4_di(&a.f[0], ((imm8 >> 2) & 3));
    dst.f[2] = SELECT4_di(&a.f[0], ((imm8 >> 4) & 3));
    dst.f[3] = SELECT4_di(&a.f[0], ((imm8 >> 6) & 3));

    return dst.v;
}

inline static ddi_4 _igen_dd_op_mm256_permute2f128_pd(ddi_4 a, ddi_4 b, int imm8) {
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
