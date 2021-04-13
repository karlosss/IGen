#include "../test_include.h"
#include "../common.h"

using namespace std;


void mm256_blend_pd_fb_verify(){
    ddi_4 a0 = _igen_dd_fb_mm256_load_pd(in);
    ddi_4 a1 = _igen_dd_fb_mm256_load_pd(in+4);
    ddi_4 a2 = _igen_dd_fb_mm256_load_pd(in+8);
    ddi_4 a3 = _igen_dd_fb_mm256_load_pd(in+12);
    ddi_4 a4 = _igen_dd_fb_mm256_load_pd(in+16);
    ddi_4 a5 = _igen_dd_fb_mm256_load_pd(in+20);
    ddi_4 a6 = _igen_dd_fb_mm256_load_pd(in+24);
    ddi_4 a7 = _igen_dd_fb_mm256_load_pd(in+28);
    ddi_4 a8 = _igen_dd_fb_mm256_load_pd(in+32);
    ddi_4 a9 = _igen_dd_fb_mm256_load_pd(in+36);
    ddi_4 a10 = _igen_dd_fb_mm256_load_pd(in+40);
    ddi_4 a11 = _igen_dd_fb_mm256_load_pd(in+44);
    ddi_4 a12 = _igen_dd_fb_mm256_load_pd(in+48);
    ddi_4 a13 = _igen_dd_fb_mm256_load_pd(in+52);
    ddi_4 a14 = _igen_dd_fb_mm256_load_pd(in+56);
    ddi_4 a15 = _igen_dd_fb_mm256_load_pd(in+60);

    ddi_4 b0 = _igen_dd_fb_mm256_load_pd(in+100);
    ddi_4 b1 = _igen_dd_fb_mm256_load_pd(in+104);
    ddi_4 b2 = _igen_dd_fb_mm256_load_pd(in+108);
    ddi_4 b3 = _igen_dd_fb_mm256_load_pd(in+112);
    ddi_4 b4 = _igen_dd_fb_mm256_load_pd(in+116);
    ddi_4 b5 = _igen_dd_fb_mm256_load_pd(in+120);
    ddi_4 b6 = _igen_dd_fb_mm256_load_pd(in+124);
    ddi_4 b7 = _igen_dd_fb_mm256_load_pd(in+128);
    ddi_4 b8 = _igen_dd_fb_mm256_load_pd(in+132);
    ddi_4 b9 = _igen_dd_fb_mm256_load_pd(in+136);
    ddi_4 b10 = _igen_dd_fb_mm256_load_pd(in+140);
    ddi_4 b11 = _igen_dd_fb_mm256_load_pd(in+144);
    ddi_4 b12 = _igen_dd_fb_mm256_load_pd(in+148);
    ddi_4 b13 = _igen_dd_fb_mm256_load_pd(in+152);
    ddi_4 b14 = _igen_dd_fb_mm256_load_pd(in+156);
    ddi_4 b15 = _igen_dd_fb_mm256_load_pd(in+160);

    ddi_4 res0 = _igen_dd_fb_mm256_blend_pd(a0, b0, 0);
    ddi_4 res1 = _igen_dd_fb_mm256_blend_pd(a1, b1, 1);
    ddi_4 res2 = _igen_dd_fb_mm256_blend_pd(a2, b2, 2);
    ddi_4 res3 = _igen_dd_fb_mm256_blend_pd(a3, b3, 3);
    ddi_4 res4 = _igen_dd_fb_mm256_blend_pd(a4, b4, 4);
    ddi_4 res5 = _igen_dd_fb_mm256_blend_pd(a5, b5, 5);
    ddi_4 res6 = _igen_dd_fb_mm256_blend_pd(a6, b6, 6);
    ddi_4 res7 = _igen_dd_fb_mm256_blend_pd(a7, b7, 7);
    ddi_4 res8 = _igen_dd_fb_mm256_blend_pd(a8, b8, 8);
    ddi_4 res9 = _igen_dd_fb_mm256_blend_pd(a9, b9, 9);
    ddi_4 res10 = _igen_dd_fb_mm256_blend_pd(a10, b10, 10);
    ddi_4 res11 = _igen_dd_fb_mm256_blend_pd(a11, b11, 11);
    ddi_4 res12 = _igen_dd_fb_mm256_blend_pd(a12, b12, 12);
    ddi_4 res13 = _igen_dd_fb_mm256_blend_pd(a13, b13, 13);
    ddi_4 res14 = _igen_dd_fb_mm256_blend_pd(a14, b14, 14);
    ddi_4 res15 = _igen_dd_fb_mm256_blend_pd(a15, b15, 15);

    _igen_dd_fb_mm256_store_pd(out+200, res0);
    _igen_dd_fb_mm256_store_pd(out+204, res1);
    _igen_dd_fb_mm256_store_pd(out+208, res2);
    _igen_dd_fb_mm256_store_pd(out+212, res3);
    _igen_dd_fb_mm256_store_pd(out+216, res4);
    _igen_dd_fb_mm256_store_pd(out+220, res5);
    _igen_dd_fb_mm256_store_pd(out+224, res6);
    _igen_dd_fb_mm256_store_pd(out+228, res7);
    _igen_dd_fb_mm256_store_pd(out+232, res8);
    _igen_dd_fb_mm256_store_pd(out+236, res9);
    _igen_dd_fb_mm256_store_pd(out+240, res10);
    _igen_dd_fb_mm256_store_pd(out+244, res11);
    _igen_dd_fb_mm256_store_pd(out+248, res12);
    _igen_dd_fb_mm256_store_pd(out+252, res13);
    _igen_dd_fb_mm256_store_pd(out+256, res14);
    _igen_dd_fb_mm256_store_pd(out+260, res15);
}


void mm256_blend_pd_opt_verify(){
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