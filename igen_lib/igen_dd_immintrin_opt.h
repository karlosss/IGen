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

#include "igen_dd_immintrin_opt/mm256_add_pd.h"

inline static ddi_4 _igen_dd_op_mm256_sub_pd(ddi_4 a, ddi_4 b) {
    ddi_4 _b;
    _b.f[0] = _mm256_permute4x64_pd(b.f[0], 0b01001110);
    _b.f[1] = _mm256_permute4x64_pd(b.f[1], 0b01001110);
    _b.f[2] = _mm256_permute4x64_pd(b.f[2], 0b01001110);
    _b.f[3] = _mm256_permute4x64_pd(b.f[3], 0b01001110);

    return _igen_dd_one_inlined_fn_mm256_add_pd(a, _b);
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

#include "igen_dd_immintrin_opt/mm256_mul_pd.h"

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
    dst = _igen_dd_one_inlined_fn_mm256_add_pd(t1, c);
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
