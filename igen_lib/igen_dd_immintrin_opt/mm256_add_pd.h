#pragma once

static inline ddi_4 _igen_dd_inlined_loop_mm256_add_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_add_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_add_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_add_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_add_dd(a.f[3], b.f[3]);

    return dst;
}

static inline ddi_4 _igen_dd_forloop_mm256_add_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;
    for(int i = 0; i < 4; ++i){
        dst.f[i] = _ia_add_dd(a.f[i], b.f[i]);
    }
    return dst;
}

static inline ddi_4 _igen_dd_one_inlined_fn_mm256_add_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif
    dd_v af0 = a.f[0];
    dd_v bf0 = b.f[0];
    dd_v s0  = af0 + bf0;
    dd_v a_0 = s0 - bf0;
    dd_v b_0 = s0 - a_0;
    dd_v da0 = af0 - a_0;
    dd_v db0 = bf0 - b_0;
    dd_v t0  = da0 + db0;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  th0   = _mm256_permute_pd(s0, 0b0101);
    dd_v  tl0   = _mm256_permute_pd(t0, 0b0101);
    dd_v  c0    = t0 + th0;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f2s0 = s0 + c0;
    dd_v f2z0 = f2s0 - s0;
    dd_v f2t0 = c0 - f2z0;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  w0    = tl0 + f2t0;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f3s0 = f2s0 + w0;
    dd_v f3z0 = f3s0 - f2s0;
    dd_v f3t0 = w0 - f3z0;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dst.f[0] = _mm256_unpacklo_pd(f3s0, f3t0);
    dst.f[1] = _ia_add_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_add_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_add_dd(a.f[3], b.f[3]);

    return dst;
}

static inline ddi_4 _igen_dd_interleaved_mm256_add_pd(ddi_4 a, ddi_4 b) {
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

static inline ddi_4 _igen_dd_no_unused_vals_mm256_add_pd(ddi_4 a, ddi_4 b) {
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

    dd_v thA = _mm256_unpackhi_pd(s0, s1);
    dd_v thB = _mm256_unpackhi_pd(s2, s3);

    dd_v tlA = _mm256_unpackhi_pd(t0, t1);
    dd_v tlB = _mm256_unpackhi_pd(t2, t3);

    dd_v sloA = _mm256_unpacklo_pd(s0, s1);
    dd_v sloB = _mm256_unpacklo_pd(s2, s3);

    dd_v tloA = _mm256_unpacklo_pd(t0, t1);
    dd_v tloB = _mm256_unpacklo_pd(t2, t3);

    dd_v cA = tloA + thA;
    dd_v cB = tloB + thB;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f2sA = sloA + cA;
    dd_v f2sB = sloB + cB;

    dd_v f2zA = f2sA - sloA;
    dd_v f2zB = f2sB - sloB;

    dd_v f2tA = cA - f2zA;
    dd_v f2tB = cB - f2zB;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  wA = tlA + f2tA;
    dd_v  wB = tlB + f2tB;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f3sA = f2sA + wA;
    dd_v f3sB = f2sB + wB;

    dd_v f3zA = f3sA - f2sA;
    dd_v f3zB = f3sB - f2sB;

    dd_v f3tA = wA - f3zA;
    dd_v f3tB = wB - f3zB;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dst.f[0] = _mm256_unpacklo_pd(f3sA, f3tA);
    dst.f[1] = _mm256_unpackhi_pd(f3sA, f3tA);
    dst.f[2] = _mm256_unpacklo_pd(f3sB, f3tB);
    dst.f[3] = _mm256_unpackhi_pd(f3sB, f3tB);

    return dst;
}
