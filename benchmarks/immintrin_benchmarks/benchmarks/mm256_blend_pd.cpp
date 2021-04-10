#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"

using namespace std;

void mm256_blend_pd_base(double* X){
    __m256d a0 = _mm256_load_pd(X);
    __m256d a1 = _mm256_load_pd(X+4);
    __m256d a2 = _mm256_load_pd(X+8);
    __m256d a3 = _mm256_load_pd(X+12);
    __m256d a4 = _mm256_load_pd(X+16);
    __m256d a5 = _mm256_load_pd(X+20);
    __m256d a6 = _mm256_load_pd(X+24);
    __m256d a7 = _mm256_load_pd(X+28);
    __m256d a8 = _mm256_load_pd(X+32);
    __m256d a9 = _mm256_load_pd(X+36);
    __m256d a10 = _mm256_load_pd(X+40);
    __m256d a11 = _mm256_load_pd(X+44);
    __m256d a12 = _mm256_load_pd(X+48);
    __m256d a13 = _mm256_load_pd(X+52);
    __m256d a14 = _mm256_load_pd(X+56);
    __m256d a15 = _mm256_load_pd(X+60);

    __m256d b0 = _mm256_load_pd(X+100);
    __m256d b1 = _mm256_load_pd(X+104);
    __m256d b2 = _mm256_load_pd(X+108);
    __m256d b3 = _mm256_load_pd(X+112);
    __m256d b4 = _mm256_load_pd(X+116);
    __m256d b5 = _mm256_load_pd(X+120);
    __m256d b6 = _mm256_load_pd(X+124);
    __m256d b7 = _mm256_load_pd(X+128);
    __m256d b8 = _mm256_load_pd(X+132);
    __m256d b9 = _mm256_load_pd(X+136);
    __m256d b10 = _mm256_load_pd(X+140);
    __m256d b11 = _mm256_load_pd(X+144);
    __m256d b12 = _mm256_load_pd(X+148);
    __m256d b13 = _mm256_load_pd(X+152);
    __m256d b14 = _mm256_load_pd(X+156);
    __m256d b15 = _mm256_load_pd(X+160);

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

    _mm256_store_pd(X+200, res0);
    _mm256_store_pd(X+204, res1);
    _mm256_store_pd(X+208, res2);
    _mm256_store_pd(X+212, res3);
    _mm256_store_pd(X+216, res4);
    _mm256_store_pd(X+220, res5);
    _mm256_store_pd(X+224, res6);
    _mm256_store_pd(X+228, res7);
    _mm256_store_pd(X+232, res8);
    _mm256_store_pd(X+236, res9);
    _mm256_store_pd(X+240, res10);
    _mm256_store_pd(X+244, res11);
    _mm256_store_pd(X+248, res12);
    _mm256_store_pd(X+252, res13);
    _mm256_store_pd(X+256, res14);
    _mm256_store_pd(X+260, res15);
}

void mm256_blend_pd(dd_I* X){
    ddi_4 a0 = _igen_dd_mm256_load_pd(X);
    ddi_4 a1 = _igen_dd_mm256_load_pd(X+4);
    ddi_4 a2 = _igen_dd_mm256_load_pd(X+8);
    ddi_4 a3 = _igen_dd_mm256_load_pd(X+12);
    ddi_4 a4 = _igen_dd_mm256_load_pd(X+16);
    ddi_4 a5 = _igen_dd_mm256_load_pd(X+20);
    ddi_4 a6 = _igen_dd_mm256_load_pd(X+24);
    ddi_4 a7 = _igen_dd_mm256_load_pd(X+28);
    ddi_4 a8 = _igen_dd_mm256_load_pd(X+32);
    ddi_4 a9 = _igen_dd_mm256_load_pd(X+36);
    ddi_4 a10 = _igen_dd_mm256_load_pd(X+40);
    ddi_4 a11 = _igen_dd_mm256_load_pd(X+44);
    ddi_4 a12 = _igen_dd_mm256_load_pd(X+48);
    ddi_4 a13 = _igen_dd_mm256_load_pd(X+52);
    ddi_4 a14 = _igen_dd_mm256_load_pd(X+56);
    ddi_4 a15 = _igen_dd_mm256_load_pd(X+60);

    ddi_4 b0 = _igen_dd_mm256_load_pd(X+100);
    ddi_4 b1 = _igen_dd_mm256_load_pd(X+104);
    ddi_4 b2 = _igen_dd_mm256_load_pd(X+108);
    ddi_4 b3 = _igen_dd_mm256_load_pd(X+112);
    ddi_4 b4 = _igen_dd_mm256_load_pd(X+116);
    ddi_4 b5 = _igen_dd_mm256_load_pd(X+120);
    ddi_4 b6 = _igen_dd_mm256_load_pd(X+124);
    ddi_4 b7 = _igen_dd_mm256_load_pd(X+128);
    ddi_4 b8 = _igen_dd_mm256_load_pd(X+132);
    ddi_4 b9 = _igen_dd_mm256_load_pd(X+136);
    ddi_4 b10 = _igen_dd_mm256_load_pd(X+140);
    ddi_4 b11 = _igen_dd_mm256_load_pd(X+144);
    ddi_4 b12 = _igen_dd_mm256_load_pd(X+148);
    ddi_4 b13 = _igen_dd_mm256_load_pd(X+152);
    ddi_4 b14 = _igen_dd_mm256_load_pd(X+156);
    ddi_4 b15 = _igen_dd_mm256_load_pd(X+160);

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

    _igen_dd_mm256_store_pd(X+200, res0);
    _igen_dd_mm256_store_pd(X+204, res1);
    _igen_dd_mm256_store_pd(X+208, res2);
    _igen_dd_mm256_store_pd(X+212, res3);
    _igen_dd_mm256_store_pd(X+216, res4);
    _igen_dd_mm256_store_pd(X+220, res5);
    _igen_dd_mm256_store_pd(X+224, res6);
    _igen_dd_mm256_store_pd(X+228, res7);
    _igen_dd_mm256_store_pd(X+232, res8);
    _igen_dd_mm256_store_pd(X+236, res9);
    _igen_dd_mm256_store_pd(X+240, res10);
    _igen_dd_mm256_store_pd(X+244, res11);
    _igen_dd_mm256_store_pd(X+248, res12);
    _igen_dd_mm256_store_pd(X+252, res13);
    _igen_dd_mm256_store_pd(X+256, res14);
    _igen_dd_mm256_store_pd(X+260, res15);
}
