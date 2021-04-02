#pragma once

#include <immintrin.h>

#include "igen_immintrin.h"
#include "igen_dd_immintrin_types.h"
#include "igen_dd_immintrin_internal.h"
#include "igen_dd_lib.h"
#include "igen_dd_math.h"

static ddi_4 _igen_dd_op_mm256_add_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _vec_add_dd(a.f[0], b.f[0]);
    dst.f[1] = _vec_add_dd(a.f[1], b.f[1]);
    dst.f[2] = _vec_add_dd(a.f[2], b.f[2]);
    dst.f[3] = _vec_add_dd(a.f[3], b.f[3]);

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

static ddi_4 _igen_dd_op_mm256_permute2f128_pd(ddi_4 a, ddi_4 b, int imm8) {
    ddi_4 dst;

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

    if (imm8 & 8) {
        dst.f[0] = zero_ddi;
        dst.f[1] = zero_ddi;
    }

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

    if (imm8 & 128) {
        dst.f[2] = zero_ddi;
        dst.f[3] = zero_ddi;
    }

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
    ddi_4 dst;

    dst.f[0] = _ia_sub_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_sub_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_sub_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_sub_dd(a.f[3], b.f[3]);

    return dst;
}

static ddi_4 _igen_dd_op_mm256_set_pd(dd_I e3, dd_I e2, dd_I e1, dd_I e0) {
    ddi_4 dst;

    dst.f[0] = e0;
    dst.f[1] = e1;
    dst.f[2] = e2;
    dst.f[3] = e3;

    return dst;
}

static ddi_4 _igen_dd_op_mm256_set1_pd(dd_I a) {
    ddi_4 dst;

    dst.f[0] = a;
    dst.f[1] = a;
    dst.f[2] = a;
    dst.f[3] = a;

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

static ddi_4 _igen_dd_op_mm256_shuffle_pd(ddi_4 a, ddi_4 b, int imm8) {
    ddi_4 dst;
    dst.f[0] = (imm8 & 1) == 0 ? a.f[0] : a.f[1];
    dst.f[2] = (imm8 & 4) == 0 ? a.f[2] : a.f[3];
    dst.f[1] = (imm8 & 2) == 0 ? b.f[0] : b.f[1];
    dst.f[3] = (imm8 & 8) == 0 ? b.f[2] : b.f[3];
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