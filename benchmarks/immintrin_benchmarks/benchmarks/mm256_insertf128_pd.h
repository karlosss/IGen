#pragma once

#define mm256_insertf128_pd_VERIFY(NAME) \
    static void mm256_insertf128_pd_ ## NAME ## _verify() { \
        ddi_4 a0 = _igen_dd_fb_mm256_load_pd(in_ddi); \
        ddi_4 a1 = _igen_dd_fb_mm256_load_pd(in_ddi+4); \
        ddi_4 a2 = _igen_dd_fb_mm256_load_pd(in_ddi+8); \
        ddi_4 a3 = _igen_dd_fb_mm256_load_pd(in_ddi+12); \
        \
        ddi_2 b0 = _igen_dd_fb_mm_load_pd(in_ddi+1024); \
        ddi_2 b1 = _igen_dd_fb_mm_load_pd(in_ddi+1026); \
        ddi_2 b2 = _igen_dd_fb_mm_load_pd(in_ddi+1028); \
        ddi_2 b3 = _igen_dd_fb_mm_load_pd(in_ddi+1030); \
        \
        ddi_4 res0 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a0, b0, 0); \
        ddi_4 res1 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a1, b1, 1); \
        ddi_4 res2 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a2, b2, 0); \
        ddi_4 res3 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a3, b3, 1); \
        \
        _igen_dd_fb_mm256_store_pd(out_ddi+2048, res0); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2052, res1); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2056, res2); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2060, res3); \
    }

#define mm256_insertf128_pd_LAT(NAME) \
    static void mm256_insertf128_pd_ ## NAME ## _lat() { \
        for(int i = 0; i < BENCHMARK_ITER; ++i){ \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi21, bool0); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi22, bool1); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi21, bool2); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi22, bool3); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi21, bool4); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi22, bool5); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi21, bool6); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi22, bool7); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi21, bool8); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi22, bool9); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi21, bool10); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi22, bool11); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi21, bool12); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi22, bool13); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi21, bool14); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi40, ddi22, bool15); \
        } \
        out_ddi4[0] = ddi40; \
    }

#define mm256_insertf128_pd_GAP(NAME) \
    static void mm256_insertf128_pd_ ## NAME ## _gap() { \
        for(int i = 0; i < BENCHMARK_ITER; ++i){ \
            ddi41 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi41, ddi20, bool0); \
            ddi42 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi42, ddi20, bool1); \
            ddi43 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi43, ddi20, bool2); \
            ddi44 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi44, ddi20, bool3); \
    \
            ddi45 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi45, ddi20, bool4); \
            ddi46 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi46, ddi20, bool5); \
            ddi47 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi47, ddi20, bool6); \
            ddi48 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi48, ddi20, bool7); \
    \
            ddi49 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi49, ddi20, bool8); \
            ddi410 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi410, ddi20, bool9); \
            ddi411 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi411, ddi20, bool10); \
            ddi412 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(ddi412, ddi20, bool11); \
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
