#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"

using namespace std;

void mm256_blend_pd_base(double* in, double* out){
    __m256d a0 = _mm256_load_pd(in);
    __m256d a1 = _mm256_load_pd(in+4);
    __m256d a2 = _mm256_load_pd(in+8);
    __m256d a3 = _mm256_load_pd(in+12);
    __m256d a4 = _mm256_load_pd(in+16);
    __m256d a5 = _mm256_load_pd(in+20);
    __m256d a6 = _mm256_load_pd(in+24);
    __m256d a7 = _mm256_load_pd(in+28);
    __m256d a8 = _mm256_load_pd(in+32);
    __m256d a9 = _mm256_load_pd(in+36);
    __m256d a10 = _mm256_load_pd(in+40);
    __m256d a11 = _mm256_load_pd(in+44);
    __m256d a12 = _mm256_load_pd(in+48);
    __m256d a13 = _mm256_load_pd(in+52);
    __m256d a14 = _mm256_load_pd(in+56);
    __m256d a15 = _mm256_load_pd(in+60);

    __m256d b0 = _mm256_load_pd(in+100);
    __m256d b1 = _mm256_load_pd(in+104);
    __m256d b2 = _mm256_load_pd(in+108);
    __m256d b3 = _mm256_load_pd(in+112);
    __m256d b4 = _mm256_load_pd(in+116);
    __m256d b5 = _mm256_load_pd(in+120);
    __m256d b6 = _mm256_load_pd(in+124);
    __m256d b7 = _mm256_load_pd(in+128);
    __m256d b8 = _mm256_load_pd(in+132);
    __m256d b9 = _mm256_load_pd(in+136);
    __m256d b10 = _mm256_load_pd(in+140);
    __m256d b11 = _mm256_load_pd(in+144);
    __m256d b12 = _mm256_load_pd(in+148);
    __m256d b13 = _mm256_load_pd(in+152);
    __m256d b14 = _mm256_load_pd(in+156);
    __m256d b15 = _mm256_load_pd(in+160);

    __m256d res0 = _mm256_blend_pd(a0, b0, 0);
    __m256d res1 = _mm256_blend_pd(a1, b1, 1);
    __m256d res2 = _mm256_blend_pd(a2, b2, 2);
    __m256d res3 = _mm256_blend_pd(a3, b3, 3);
    __m256d res4 = _mm256_blend_pd(a4, b4, 4);
    __m256d res5 = _mm256_blend_pd(a5, b5, 5);
    __m256d res6 = _mm256_blend_pd(a6, b6, 6);
    __m256d res7 = _mm256_blend_pd(a7, b7, 7);
    __m256d res8 = _mm256_blend_pd(a8, b8, 8);
    __m256d res9 = _mm256_blend_pd(a9, b9, 9);
    __m256d res10 = _mm256_blend_pd(a10, b10, 10);
    __m256d res11 = _mm256_blend_pd(a11, b11, 11);
    __m256d res12 = _mm256_blend_pd(a12, b12, 12);
    __m256d res13 = _mm256_blend_pd(a13, b13, 13);
    __m256d res14 = _mm256_blend_pd(a14, b14, 14);
    __m256d res15 = _mm256_blend_pd(a15, b15, 15);

    _mm256_store_pd(out+200, res0);
    _mm256_store_pd(out+204, res1);
    _mm256_store_pd(out+208, res2);
    _mm256_store_pd(out+212, res3);
    _mm256_store_pd(out+216, res4);
    _mm256_store_pd(out+220, res5);
    _mm256_store_pd(out+224, res6);
    _mm256_store_pd(out+228, res7);
    _mm256_store_pd(out+232, res8);
    _mm256_store_pd(out+236, res9);
    _mm256_store_pd(out+240, res10);
    _mm256_store_pd(out+244, res11);
    _mm256_store_pd(out+248, res12);
    _mm256_store_pd(out+252, res13);
    _mm256_store_pd(out+256, res14);
    _mm256_store_pd(out+260, res15);
}

void mm256_blend_pd(dd_I* in, dd_I* out){
    ddi_4 a0 = _igen_dd_mm256_load_pd(in);
    ddi_4 a1 = _igen_dd_mm256_load_pd(in+4);
    ddi_4 a2 = _igen_dd_mm256_load_pd(in+8);
    ddi_4 a3 = _igen_dd_mm256_load_pd(in+12);
    ddi_4 a4 = _igen_dd_mm256_load_pd(in+16);
    ddi_4 a5 = _igen_dd_mm256_load_pd(in+20);
    ddi_4 a6 = _igen_dd_mm256_load_pd(in+24);
    ddi_4 a7 = _igen_dd_mm256_load_pd(in+28);
    ddi_4 a8 = _igen_dd_mm256_load_pd(in+32);
    ddi_4 a9 = _igen_dd_mm256_load_pd(in+36);
    ddi_4 a10 = _igen_dd_mm256_load_pd(in+40);
    ddi_4 a11 = _igen_dd_mm256_load_pd(in+44);
    ddi_4 a12 = _igen_dd_mm256_load_pd(in+48);
    ddi_4 a13 = _igen_dd_mm256_load_pd(in+52);
    ddi_4 a14 = _igen_dd_mm256_load_pd(in+56);
    ddi_4 a15 = _igen_dd_mm256_load_pd(in+60);

    ddi_4 b0 = _igen_dd_mm256_load_pd(in+100);
    ddi_4 b1 = _igen_dd_mm256_load_pd(in+104);
    ddi_4 b2 = _igen_dd_mm256_load_pd(in+108);
    ddi_4 b3 = _igen_dd_mm256_load_pd(in+112);
    ddi_4 b4 = _igen_dd_mm256_load_pd(in+116);
    ddi_4 b5 = _igen_dd_mm256_load_pd(in+120);
    ddi_4 b6 = _igen_dd_mm256_load_pd(in+124);
    ddi_4 b7 = _igen_dd_mm256_load_pd(in+128);
    ddi_4 b8 = _igen_dd_mm256_load_pd(in+132);
    ddi_4 b9 = _igen_dd_mm256_load_pd(in+136);
    ddi_4 b10 = _igen_dd_mm256_load_pd(in+140);
    ddi_4 b11 = _igen_dd_mm256_load_pd(in+144);
    ddi_4 b12 = _igen_dd_mm256_load_pd(in+148);
    ddi_4 b13 = _igen_dd_mm256_load_pd(in+152);
    ddi_4 b14 = _igen_dd_mm256_load_pd(in+156);
    ddi_4 b15 = _igen_dd_mm256_load_pd(in+160);

    ddi_4 res0 = _igen_dd_mm256_blend_pd(a0, b0, 0);
    ddi_4 res1 = _igen_dd_mm256_blend_pd(a1, b1, 1);
    ddi_4 res2 = _igen_dd_mm256_blend_pd(a2, b2, 2);
    ddi_4 res3 = _igen_dd_mm256_blend_pd(a3, b3, 3);
    ddi_4 res4 = _igen_dd_mm256_blend_pd(a4, b4, 4);
    ddi_4 res5 = _igen_dd_mm256_blend_pd(a5, b5, 5);
    ddi_4 res6 = _igen_dd_mm256_blend_pd(a6, b6, 6);
    ddi_4 res7 = _igen_dd_mm256_blend_pd(a7, b7, 7);
    ddi_4 res8 = _igen_dd_mm256_blend_pd(a8, b8, 8);
    ddi_4 res9 = _igen_dd_mm256_blend_pd(a9, b9, 9);
    ddi_4 res10 = _igen_dd_mm256_blend_pd(a10, b10, 10);
    ddi_4 res11 = _igen_dd_mm256_blend_pd(a11, b11, 11);
    ddi_4 res12 = _igen_dd_mm256_blend_pd(a12, b12, 12);
    ddi_4 res13 = _igen_dd_mm256_blend_pd(a13, b13, 13);
    ddi_4 res14 = _igen_dd_mm256_blend_pd(a14, b14, 14);
    ddi_4 res15 = _igen_dd_mm256_blend_pd(a15, b15, 15);

    _igen_dd_mm256_store_pd(out+200, res0);
    _igen_dd_mm256_store_pd(out+204, res1);
    _igen_dd_mm256_store_pd(out+208, res2);
    _igen_dd_mm256_store_pd(out+212, res3);
    _igen_dd_mm256_store_pd(out+216, res4);
    _igen_dd_mm256_store_pd(out+220, res5);
    _igen_dd_mm256_store_pd(out+224, res6);
    _igen_dd_mm256_store_pd(out+228, res7);
    _igen_dd_mm256_store_pd(out+232, res8);
    _igen_dd_mm256_store_pd(out+236, res9);
    _igen_dd_mm256_store_pd(out+240, res10);
    _igen_dd_mm256_store_pd(out+244, res11);
    _igen_dd_mm256_store_pd(out+248, res12);
    _igen_dd_mm256_store_pd(out+252, res13);
    _igen_dd_mm256_store_pd(out+256, res14);
    _igen_dd_mm256_store_pd(out+260, res15);
}
