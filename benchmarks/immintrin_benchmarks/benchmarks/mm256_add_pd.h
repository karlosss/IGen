#pragma once

#define mm256_add_pd_VERIFY(NAME) \
    static void mm256_add_pd_ ## NAME ## _verify() { \
        ddi_4 a0 = _igen_dd_fb_mm256_load_pd(in_ddi); \
        ddi_4 a1 = _igen_dd_fb_mm256_load_pd(in_ddi+4); \
        ddi_4 a2 = _igen_dd_fb_mm256_load_pd(in_ddi+8); \
        ddi_4 a3 = _igen_dd_fb_mm256_load_pd(in_ddi+12); \
        ddi_4 a4 = _igen_dd_fb_mm256_load_pd(in_ddi+16); \
        ddi_4 a5 = _igen_dd_fb_mm256_load_pd(in_ddi+20); \
        ddi_4 a6 = _igen_dd_fb_mm256_load_pd(in_ddi+24); \
        ddi_4 a7 = _igen_dd_fb_mm256_load_pd(in_ddi+28); \
        ddi_4 a8 = _igen_dd_fb_mm256_load_pd(in_ddi+32); \
        ddi_4 a9 = _igen_dd_fb_mm256_load_pd(in_ddi+36); \
        ddi_4 a10 = _igen_dd_fb_mm256_load_pd(in_ddi+40); \
        ddi_4 a11 = _igen_dd_fb_mm256_load_pd(in_ddi+44); \
        ddi_4 a12 = _igen_dd_fb_mm256_load_pd(in_ddi+48); \
        ddi_4 a13 = _igen_dd_fb_mm256_load_pd(in_ddi+52); \
        ddi_4 a14 = _igen_dd_fb_mm256_load_pd(in_ddi+56); \
        ddi_4 a15 = _igen_dd_fb_mm256_load_pd(in_ddi+60); \
                                                          \
        ddi_4 b0 = _igen_dd_fb_mm256_load_pd(in_ddi+100); \
        ddi_4 b1 = _igen_dd_fb_mm256_load_pd(in_ddi+104); \
        ddi_4 b2 = _igen_dd_fb_mm256_load_pd(in_ddi+108); \
        ddi_4 b3 = _igen_dd_fb_mm256_load_pd(in_ddi+112); \
        ddi_4 b4 = _igen_dd_fb_mm256_load_pd(in_ddi+116); \
        ddi_4 b5 = _igen_dd_fb_mm256_load_pd(in_ddi+120); \
        ddi_4 b6 = _igen_dd_fb_mm256_load_pd(in_ddi+124); \
        ddi_4 b7 = _igen_dd_fb_mm256_load_pd(in_ddi+128); \
        ddi_4 b8 = _igen_dd_fb_mm256_load_pd(in_ddi+132); \
        ddi_4 b9 = _igen_dd_fb_mm256_load_pd(in_ddi+136); \
        ddi_4 b10 = _igen_dd_fb_mm256_load_pd(in_ddi+140); \
        ddi_4 b11 = _igen_dd_fb_mm256_load_pd(in_ddi+144); \
        ddi_4 b12 = _igen_dd_fb_mm256_load_pd(in_ddi+148); \
        ddi_4 b13 = _igen_dd_fb_mm256_load_pd(in_ddi+152); \
        ddi_4 b14 = _igen_dd_fb_mm256_load_pd(in_ddi+156); \
        ddi_4 b15 = _igen_dd_fb_mm256_load_pd(in_ddi+160); \
                                                       \
        ddi_4 res0 = _igen_dd_ ## NAME ## _mm256_add_pd(a0, b0); \
        ddi_4 res1 = _igen_dd_ ## NAME ## _mm256_add_pd(a1, b1); \
        ddi_4 res2 = _igen_dd_ ## NAME ## _mm256_add_pd(a2, b2); \
        ddi_4 res3 = _igen_dd_ ## NAME ## _mm256_add_pd(a3, b3); \
        ddi_4 res4 = _igen_dd_ ## NAME ## _mm256_add_pd(a4, b4); \
        ddi_4 res5 = _igen_dd_ ## NAME ## _mm256_add_pd(a5, b5); \
        ddi_4 res6 = _igen_dd_ ## NAME ## _mm256_add_pd(a6, b6); \
        ddi_4 res7 = _igen_dd_ ## NAME ## _mm256_add_pd(a7, b7); \
        ddi_4 res8 = _igen_dd_ ## NAME ## _mm256_add_pd(a8, b8); \
        ddi_4 res9 = _igen_dd_ ## NAME ## _mm256_add_pd(a9, b9); \
        ddi_4 res10 = _igen_dd_ ## NAME ## _mm256_add_pd(a10, b10); \
        ddi_4 res11 = _igen_dd_ ## NAME ## _mm256_add_pd(a11, b11); \
        ddi_4 res12 = _igen_dd_ ## NAME ## _mm256_add_pd(a12, b12); \
        ddi_4 res13 = _igen_dd_ ## NAME ## _mm256_add_pd(a13, b13); \
        ddi_4 res14 = _igen_dd_ ## NAME ## _mm256_add_pd(a14, b14); \
        ddi_4 res15 = _igen_dd_ ## NAME ## _mm256_add_pd(a15, b15); \
                                                       \
        _igen_dd_fb_mm256_store_pd(out_ddi+200, res0); \
        _igen_dd_fb_mm256_store_pd(out_ddi+204, res1); \
        _igen_dd_fb_mm256_store_pd(out_ddi+208, res2); \
        _igen_dd_fb_mm256_store_pd(out_ddi+212, res3); \
        _igen_dd_fb_mm256_store_pd(out_ddi+216, res4); \
        _igen_dd_fb_mm256_store_pd(out_ddi+220, res5); \
        _igen_dd_fb_mm256_store_pd(out_ddi+224, res6); \
        _igen_dd_fb_mm256_store_pd(out_ddi+228, res7); \
        _igen_dd_fb_mm256_store_pd(out_ddi+232, res8); \
        _igen_dd_fb_mm256_store_pd(out_ddi+236, res9); \
        _igen_dd_fb_mm256_store_pd(out_ddi+240, res10); \
        _igen_dd_fb_mm256_store_pd(out_ddi+244, res11); \
        _igen_dd_fb_mm256_store_pd(out_ddi+248, res12); \
        _igen_dd_fb_mm256_store_pd(out_ddi+252, res13); \
        _igen_dd_fb_mm256_store_pd(out_ddi+256, res14); \
        _igen_dd_fb_mm256_store_pd(out_ddi+260, res15); \
    }

#define mm256_add_pd_LAT(NAME) \
    static void mm256_add_pd_ ## NAME ## _lat() { \
        for(int i = 0; i < BENCHMARK_ITER; ++i){ \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi40, ddi42); \
        } \
        out_ddi4[0] = ddi40; \
    }

#define mm256_add_pd_GAP(NAME) \
    static void mm256_add_pd_ ## NAME ## _gap() { \
        for(int i = 0; i < BENCHMARK_ITER; ++i){ \
            ddi41 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi41, ddi40); \
            ddi42 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi42, ddi40); \
            ddi43 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi43, ddi40); \
            ddi44 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi44, ddi40); \
            \
            ddi45 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi45, ddi40); \
            ddi46 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi46, ddi40); \
            ddi47 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi47, ddi40); \
            ddi48 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi48, ddi40); \
            \
            ddi49 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi49, ddi40); \
            ddi410 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi410, ddi40); \
            ddi411 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi411, ddi40); \
            ddi412 = _igen_dd_ ## NAME ## _mm256_add_pd(ddi412, ddi40); \
            } \
        \
        out_ddi4[1] = ddi41; \
        out_ddi4[2] = ddi42; \
        out_ddi4[3] = ddi43; \
        out_ddi4[4] = ddi44; \
        out_ddi4[5] = ddi45; \
        out_ddi4[6] = ddi46; \
        out_ddi4[7] = ddi47; \
        out_ddi4[8] = ddi48; \
        out_ddi4[9] = ddi49; \
        out_ddi4[10] = ddi410; \
        out_ddi4[11] = ddi411; \
        out_ddi4[12] = ddi412; \
    }