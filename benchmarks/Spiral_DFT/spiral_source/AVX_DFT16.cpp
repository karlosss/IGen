
/*
 * This code was generated by Spiral 8.0.0, www.spiral.net
 */

#include <math.h>
#include <immintrin.h>

void init_AVX_DFT16(double a) {
}

void AVX_DFT16(double  *Y, double  *X) {
    __m256d s211, s212, s213, s214, s215, s216, s217, s218
    , s219, s220, s221, s222, s223, s224, s225, s226
    , s227, s228, s229, s230, s231, s232, s233, s234
    , s235, s236, s237, s238, s239, s240, s241, s242
    , s243, s244, s245, s246, s247, s248, s249, s250
    , s251, s252, s253, s254, s255, s256, s257, s258
    , s259, s260, s261, s262, s263, s264, s265, s266
    , s267, s268, s269, s270, s271, s272, s273, s274
    , s275, s276, s277, s278, s279, s280, t129, t130
    , t131, t132, t133, t134, t135, t136, t137, t138
    , t139, t140, t141, t142, t143, t144, t145, t146
    , t147, t148, t149, t150, t151, t152, t153, t154
    , t155, t156, t157, t158, t159, t160;
    __m256d  *a45, *a46;
    a45 = ((__m256d  *) X);
    s211 = *(a45);
    s212 = *((a45 + 1));
    s213 = _mm256_permute2f128_pd(s211, s212, (0) | ((2) << 4));
    s214 = _mm256_permute2f128_pd(s211, s212, (1) | ((3) << 4));
    s215 = _mm256_unpacklo_pd(s213, s214);
    s216 = _mm256_unpackhi_pd(s213, s214);
    s217 = *((a45 + 4));
    s218 = *((a45 + 5));
    s219 = _mm256_permute2f128_pd(s217, s218, (0) | ((2) << 4));
    s220 = _mm256_permute2f128_pd(s217, s218, (1) | ((3) << 4));
    s221 = _mm256_unpacklo_pd(s219, s220);
    s222 = _mm256_unpackhi_pd(s219, s220);
    t129 = _mm256_add_pd(s215, s221);
    t130 = _mm256_add_pd(s216, s222);
    t131 = _mm256_sub_pd(s215, s221);
    t132 = _mm256_sub_pd(s216, s222);
    s223 = *((a45 + 2));
    s224 = *((a45 + 3));
    s225 = _mm256_permute2f128_pd(s223, s224, (0) | ((2) << 4));
    s226 = _mm256_permute2f128_pd(s223, s224, (1) | ((3) << 4));
    s227 = _mm256_unpacklo_pd(s225, s226);
    s228 = _mm256_unpackhi_pd(s225, s226);
    s229 = *((a45 + 6));
    s230 = *((a45 + 7));
    s231 = _mm256_permute2f128_pd(s229, s230, (0) | ((2) << 4));
    s232 = _mm256_permute2f128_pd(s229, s230, (1) | ((3) << 4));
    s233 = _mm256_unpacklo_pd(s231, s232);
    s234 = _mm256_unpackhi_pd(s231, s232);
    t133 = _mm256_add_pd(s227, s233);
    t134 = _mm256_add_pd(s228, s234);
    t135 = _mm256_sub_pd(s227, s233);
    t136 = _mm256_sub_pd(s228, s234);
    t137 = _mm256_add_pd(t129, t133);
    t138 = _mm256_add_pd(t130, t134);
    t139 = _mm256_sub_pd(t129, t133);
    t140 = _mm256_sub_pd(t130, t134);
    t141 = _mm256_sub_pd(t131, t136);
    t142 = _mm256_add_pd(t132, t135);
    t143 = _mm256_add_pd(t131, t136);
    t144 = _mm256_sub_pd(t132, t135);
    s235 = _mm256_unpacklo_pd(t137, t141);
    s236 = _mm256_unpackhi_pd(t137, t141);
    s237 = _mm256_unpacklo_pd(t138, t142);
    s238 = _mm256_unpackhi_pd(t138, t142);
    s239 = _mm256_permute2f128_pd(s235, s236, (0) | ((2) << 4));
    s240 = _mm256_permute2f128_pd(s235, s236, (1) | ((3) << 4));
    s241 = _mm256_permute2f128_pd(s237, s238, (0) | ((2) << 4));
    s242 = _mm256_permute2f128_pd(s237, s238, (1) | ((3) << 4));
    s243 = _mm256_unpacklo_pd(t139, t143);
    s244 = _mm256_unpackhi_pd(t139, t143);
    s245 = _mm256_unpacklo_pd(t140, t144);
    s246 = _mm256_unpackhi_pd(t140, t144);
    s247 = _mm256_permute2f128_pd(s243, s244, (0) | ((2) << 4));
    s248 = _mm256_permute2f128_pd(s243, s244, (1) | ((3) << 4));
    s249 = _mm256_permute2f128_pd(s245, s246, (0) | ((2) << 4));
    s250 = _mm256_permute2f128_pd(s245, s246, (1) | ((3) << 4));
    s251 = _mm256_permute2f128_pd(s239, s247, (0) | ((2) << 4));
    s252 = _mm256_permute2f128_pd(s239, s247, (1) | ((3) << 4));
    s253 = _mm256_permute2f128_pd(s240, s248, (0) | ((2) << 4));
    s254 = _mm256_permute2f128_pd(s240, s248, (1) | ((3) << 4));
    s255 = _mm256_permute2f128_pd(s241, s249, (0) | ((2) << 4));
    s256 = _mm256_permute2f128_pd(s241, s249, (1) | ((3) << 4));
    s257 = _mm256_permute2f128_pd(s242, s250, (0) | ((2) << 4));
    s258 = _mm256_permute2f128_pd(s242, s250, (1) | ((3) << 4));
    s259 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.70710678118654757), 0.0, 0.70710678118654757, 1.0), s253), _mm256_mul_pd(_mm256_set_pd(0.70710678118654757, 1.0, 0.70710678118654757, 0.0), s257));
    s260 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.70710678118654757, 1.0, 0.70710678118654757, 0.0), s253), _mm256_mul_pd(_mm256_set_pd((-0.70710678118654757), 0.0, 0.70710678118654757, 1.0), s257));
    t145 = _mm256_add_pd(s251, s259);
    t146 = _mm256_add_pd(s255, s260);
    t147 = _mm256_sub_pd(s251, s259);
    t148 = _mm256_sub_pd(s255, s260);
    s261 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s252), _mm256_mul_pd(_mm256_set_pd(0.92387953251128674, 0.70710678118654757, 0.38268343236508978, 0.0), s256));
    s262 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.92387953251128674, 0.70710678118654757, 0.38268343236508978, 0.0), s252), _mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s256));
    s263 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.92387953251128674), (-0.70710678118654757), 0.38268343236508978, 1.0), s254), _mm256_mul_pd(_mm256_set_pd((-0.38268343236508978), 0.70710678118654757, 0.92387953251128674, 0.0), s258));
    s264 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd((-0.38268343236508978), 0.70710678118654757, 0.92387953251128674, 0.0), s254), _mm256_mul_pd(_mm256_set_pd((-0.92387953251128674), (-0.70710678118654757), 0.38268343236508978, 1.0), s258));
    t149 = _mm256_add_pd(s261, s263);
    t150 = _mm256_add_pd(s262, s264);
    t151 = _mm256_sub_pd(s261, s263);
    t152 = _mm256_sub_pd(s262, s264);
    t153 = _mm256_add_pd(t145, t149);
    t154 = _mm256_add_pd(t146, t150);
    t155 = _mm256_sub_pd(t145, t149);
    t156 = _mm256_sub_pd(t146, t150);
    s265 = _mm256_unpacklo_pd(t153, t154);
    s266 = _mm256_unpackhi_pd(t153, t154);
    a46 = ((__m256d  *) Y);
    s267 = _mm256_permute2f128_pd(s265, s266, (0) | ((2) << 4));
    *(a46) = s267;
    s268 = _mm256_permute2f128_pd(s265, s266, (1) | ((3) << 4));
    *((a46 + 1)) = s268;
    s269 = _mm256_unpacklo_pd(t155, t156);
    s270 = _mm256_unpackhi_pd(t155, t156);
    s271 = _mm256_permute2f128_pd(s269, s270, (0) | ((2) << 4));
    *((a46 + 4)) = s271;
    s272 = _mm256_permute2f128_pd(s269, s270, (1) | ((3) << 4));
    *((a46 + 5)) = s272;
    t157 = _mm256_sub_pd(t147, t152);
    t158 = _mm256_add_pd(t148, t151);
    t159 = _mm256_add_pd(t147, t152);
    t160 = _mm256_sub_pd(t148, t151);
    s273 = _mm256_unpacklo_pd(t157, t158);
    s274 = _mm256_unpackhi_pd(t157, t158);
    s275 = _mm256_permute2f128_pd(s273, s274, (0) | ((2) << 4));
    *((a46 + 2)) = s275;
    s276 = _mm256_permute2f128_pd(s273, s274, (1) | ((3) << 4));
    *((a46 + 3)) = s276;
    s277 = _mm256_unpacklo_pd(t159, t160);
    s278 = _mm256_unpackhi_pd(t159, t160);
    s279 = _mm256_permute2f128_pd(s277, s278, (0) | ((2) << 4));
    *((a46 + 6)) = s279;
    s280 = _mm256_permute2f128_pd(s277, s278, (1) | ((3) << 4));
    *((a46 + 7)) = s280;
}
