#include "igen_dd_lib.h"
dd_I cospi(dd_I x);
dd_I sinpi(dd_I x);

static dd_I D1[128];

void init_DFT64(dd_I a) {
  for (int i838 = 0; i838 <= 7; i838++) {
    for (int i845 = 0; i845 <= 3; i845++) {
      dd_I _t1 = _ia_cvt_i2dd((2 * (i838 * i845)));
      dd_I _t2 = _ia_set_dd(-64, 0.0, 64, 0.0);
      dd_I _t3 = _ia_div_dd(_t1, _t2);
      D1[((16 * i838) + (4 * i845))] = cospi(_t3);
      dd_I _t4 = _ia_cvt_i2dd((2 * (((2 * (i838 * i845)) + 1) / 2)));
      dd_I _t5 = _ia_set_dd(-64, 0.0, 64, 0.0);
      dd_I _t6 = _ia_div_dd(_t4, _t5);
      D1[(1 + (16 * i838) + (4 * i845))] = sinpi(_t6);
      dd_I _t7 = _ia_cvt_i2dd((2 * (i838 * (4 + i845))));
      dd_I _t8 = _ia_set_dd(-64, 0.0, 64, 0.0);
      dd_I _t9 = _ia_div_dd(_t7, _t8);
      D1[(2 + (16 * i838) + (4 * i845))] = cospi(_t9);
      dd_I _t10 = _ia_cvt_i2dd((2 * (((2 * (i838 * (4 + i845))) + 1) / 2)));
      dd_I _t11 = _ia_set_dd(-64, 0.0, 64, 0.0);
      dd_I _t12 = _ia_div_dd(_t10, _t11);
      D1[(3 + (16 * i838) + (4 * i845))] = sinpi(_t12);
    }
  }
}

void DFT64(dd_I *Y, dd_I *X) {
  static dd_I T129[128];
  for (int i838 = 0; i838 <= 7; i838++) {
    int a2252;
    int a2253;
    int a2254;
    int a2255;
    int a2256;
    int a2257;
    int a2258;
    int a2259;
    int a2260;
    int a2261;
    int a2262;
    int a2263;
    int a2264;
    int a2265;
    int a2266;
    int a2267;
    int a2272;
    int a2273;
    int a2274;
    int a2275;
    int a2276;
    int a2277;
    int a2278;
    int a2279;
    int a2280;
    int a2281;
    int a2282;
    int a2283;
    int a2284;
    int a2285;
    int a2286;
    int a2287;
    dd_I a2268;
    dd_I a2269;
    dd_I a2270;
    dd_I a2271;
    dd_I s6478;
    dd_I s6479;
    dd_I s6480;
    dd_I s6481;
    dd_I t5454;
    dd_I t5455;
    dd_I t5456;
    dd_I t5457;
    dd_I t5458;
    dd_I t5459;
    dd_I t5460;
    dd_I t5461;
    dd_I t5462;
    dd_I t5463;
    dd_I t5464;
    dd_I t5465;
    dd_I t5466;
    dd_I t5467;
    dd_I t5468;
    dd_I t5469;
    dd_I t5470;
    dd_I t5471;
    dd_I t5472;
    dd_I t5473;
    dd_I t5474;
    dd_I t5475;
    dd_I t5476;
    dd_I t5477;
    dd_I t5478;
    dd_I t5479;
    dd_I t5480;
    dd_I t5481;
    dd_I t5482;
    dd_I t5483;
    dd_I t5484;
    dd_I t5485;
    dd_I t5486;
    dd_I t5487;
    dd_I t5488;
    dd_I t5489;
    dd_I t5490;
    dd_I t5491;
    dd_I t5492;
    dd_I t5493;
    dd_I t5494;
    dd_I t5495;
    dd_I t5496;
    dd_I t5497;
    a2252 = (2 * i838);
    a2253 = (a2252 + 1);
    a2254 = (a2252 + 64);
    a2255 = (a2252 + 65);
    t5454 = _ia_add_dd(*((X + a2252)), *((X + a2254)));
    t5455 = _ia_add_dd(*((X + a2253)), *((X + a2255)));
    t5456 = _ia_sub_dd(*((X + a2252)), *((X + a2254)));
    t5457 = _ia_sub_dd(*((X + a2253)), *((X + a2255)));
    a2256 = (a2252 + 32);
    a2257 = (a2252 + 33);
    a2258 = (a2252 + 96);
    a2259 = (a2252 + 97);
    t5458 = _ia_add_dd(*((X + a2256)), *((X + a2258)));
    t5459 = _ia_add_dd(*((X + a2257)), *((X + a2259)));
    t5460 = _ia_sub_dd(*((X + a2256)), *((X + a2258)));
    t5461 = _ia_sub_dd(*((X + a2257)), *((X + a2259)));
    t5462 = _ia_add_dd(t5454, t5458);
    t5463 = _ia_add_dd(t5455, t5459);
    t5464 = _ia_sub_dd(t5454, t5458);
    t5465 = _ia_sub_dd(t5455, t5459);
    t5466 = _ia_sub_dd(t5456, t5461);
    t5467 = _ia_add_dd(t5457, t5460);
    t5468 = _ia_add_dd(t5456, t5461);
    t5469 = _ia_sub_dd(t5457, t5460);
    a2260 = (a2252 + 16);
    a2261 = (a2252 + 17);
    a2262 = (a2252 + 80);
    a2263 = (a2252 + 81);
    t5470 = _ia_add_dd(*((X + a2260)), *((X + a2262)));
    t5471 = _ia_add_dd(*((X + a2261)), *((X + a2263)));
    t5472 = _ia_sub_dd(*((X + a2260)), *((X + a2262)));
    t5473 = _ia_sub_dd(*((X + a2261)), *((X + a2263)));
    a2264 = (a2252 + 48);
    a2265 = (a2252 + 49);
    a2266 = (a2252 + 112);
    a2267 = (a2252 + 113);
    t5474 = _ia_add_dd(*((X + a2264)), *((X + a2266)));
    t5475 = _ia_add_dd(*((X + a2265)), *((X + a2267)));
    t5476 = _ia_sub_dd(*((X + a2264)), *((X + a2266)));
    t5477 = _ia_sub_dd(*((X + a2265)), *((X + a2267)));
    t5478 = _ia_add_dd(t5470, t5474);
    t5479 = _ia_add_dd(t5471, t5475);
    t5480 = _ia_sub_dd(t5470, t5474);
    t5481 = _ia_sub_dd(t5471, t5475);
    dd_I _t13 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
    dd_I _t14 = _ia_sub_dd(t5472, t5477);
    a2268 = _ia_mul_dd(_t13, _t14);
    dd_I _t15 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
    dd_I _t16 = _ia_add_dd(t5473, t5476);
    a2269 = _ia_mul_dd(_t15, _t16);
    s6478 = _ia_sub_dd(a2268, a2269);
    s6479 = _ia_add_dd(a2268, a2269);
    dd_I _t17 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
    dd_I _t18 = _ia_add_dd(t5472, t5477);
    a2270 = _ia_mul_dd(_t17, _t18);
    dd_I _t19 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
    dd_I _t20 = _ia_sub_dd(t5473, t5476);
    a2271 = _ia_mul_dd(_t19, _t20);
    s6480 = _ia_add_dd(a2270, a2271);
    s6481 = _ia_sub_dd(a2270, a2271);
    t5482 = _ia_add_dd(t5462, t5478);
    t5483 = _ia_add_dd(t5463, t5479);
    t5484 = _ia_sub_dd(t5462, t5478);
    t5485 = _ia_sub_dd(t5463, t5479);
    a2272 = (16 * i838);
    a2273 = (a2272 + 1);
    a2274 = (a2272 + 2);
    a2275 = (a2272 + 3);
    dd_I _t21 = _ia_mul_dd(*((D1 + a2272)), t5482);
    dd_I _t22 = _ia_mul_dd(*((D1 + a2273)), t5483);
    *((T129 + a2272)) = _ia_sub_dd(_t21, _t22);
    dd_I _t23 = _ia_mul_dd(*((D1 + a2273)), t5482);
    dd_I _t24 = _ia_mul_dd(*((D1 + a2272)), t5483);
    *((T129 + a2273)) = _ia_add_dd(_t23, _t24);
    a2276 = (a2272 + 8);
    dd_I _t25 = _ia_mul_dd(*((D1 + a2274)), t5484);
    dd_I _t26 = _ia_mul_dd(*((D1 + a2275)), t5485);
    *((T129 + a2276)) = _ia_sub_dd(_t25, _t26);
    a2277 = (a2272 + 9);
    dd_I _t27 = _ia_mul_dd(*((D1 + a2275)), t5484);
    dd_I _t28 = _ia_mul_dd(*((D1 + a2274)), t5485);
    *((T129 + a2277)) = _ia_add_dd(_t27, _t28);
    t5486 = _ia_add_dd(t5466, s6478);
    t5487 = _ia_add_dd(t5467, s6479);
    t5488 = _ia_sub_dd(t5466, s6478);
    t5489 = _ia_sub_dd(t5467, s6479);
    a2278 = (a2272 + 4);
    a2279 = (a2272 + 5);
    a2280 = (a2272 + 6);
    a2281 = (a2272 + 7);
    dd_I _t29 = _ia_mul_dd(*((D1 + a2278)), t5486);
    dd_I _t30 = _ia_mul_dd(*((D1 + a2279)), t5487);
    *((T129 + a2274)) = _ia_sub_dd(_t29, _t30);
    dd_I _t31 = _ia_mul_dd(*((D1 + a2279)), t5486);
    dd_I _t32 = _ia_mul_dd(*((D1 + a2278)), t5487);
    *((T129 + a2275)) = _ia_add_dd(_t31, _t32);
    a2282 = (a2272 + 10);
    dd_I _t33 = _ia_mul_dd(*((D1 + a2280)), t5488);
    dd_I _t34 = _ia_mul_dd(*((D1 + a2281)), t5489);
    *((T129 + a2282)) = _ia_sub_dd(_t33, _t34);
    a2283 = (a2272 + 11);
    dd_I _t35 = _ia_mul_dd(*((D1 + a2281)), t5488);
    dd_I _t36 = _ia_mul_dd(*((D1 + a2280)), t5489);
    *((T129 + a2283)) = _ia_add_dd(_t35, _t36);
    t5490 = _ia_sub_dd(t5464, t5481);
    t5491 = _ia_add_dd(t5465, t5480);
    t5492 = _ia_add_dd(t5464, t5481);
    t5493 = _ia_sub_dd(t5465, t5480);
    dd_I _t37 = _ia_mul_dd(*((D1 + a2276)), t5490);
    dd_I _t38 = _ia_mul_dd(*((D1 + a2277)), t5491);
    *((T129 + a2278)) = _ia_sub_dd(_t37, _t38);
    dd_I _t39 = _ia_mul_dd(*((D1 + a2277)), t5490);
    dd_I _t40 = _ia_mul_dd(*((D1 + a2276)), t5491);
    *((T129 + a2279)) = _ia_add_dd(_t39, _t40);
    a2284 = (a2272 + 12);
    dd_I _t41 = _ia_mul_dd(*((D1 + a2282)), t5492);
    dd_I _t42 = _ia_mul_dd(*((D1 + a2283)), t5493);
    *((T129 + a2284)) = _ia_sub_dd(_t41, _t42);
    a2285 = (a2272 + 13);
    dd_I _t43 = _ia_mul_dd(*((D1 + a2283)), t5492);
    dd_I _t44 = _ia_mul_dd(*((D1 + a2282)), t5493);
    *((T129 + a2285)) = _ia_add_dd(_t43, _t44);
    t5494 = _ia_sub_dd(t5468, s6480);
    t5495 = _ia_add_dd(t5469, s6481);
    t5496 = _ia_add_dd(t5468, s6480);
    t5497 = _ia_sub_dd(t5469, s6481);
    a2286 = (a2272 + 14);
    a2287 = (a2272 + 15);
    dd_I _t45 = _ia_mul_dd(*((D1 + a2284)), t5494);
    dd_I _t46 = _ia_mul_dd(*((D1 + a2285)), t5495);
    *((T129 + a2280)) = _ia_sub_dd(_t45, _t46);
    dd_I _t47 = _ia_mul_dd(*((D1 + a2285)), t5494);
    dd_I _t48 = _ia_mul_dd(*((D1 + a2284)), t5495);
    *((T129 + a2281)) = _ia_add_dd(_t47, _t48);
    dd_I _t49 = _ia_mul_dd(*((D1 + a2286)), t5496);
    dd_I _t50 = _ia_mul_dd(*((D1 + a2287)), t5497);
    *((T129 + a2286)) = _ia_sub_dd(_t49, _t50);
    dd_I _t51 = _ia_mul_dd(*((D1 + a2287)), t5496);
    dd_I _t52 = _ia_mul_dd(*((D1 + a2286)), t5497);
    *((T129 + a2287)) = _ia_add_dd(_t51, _t52);
  }
  for (int i837 = 0; i837 <= 7; i837++) {
    int a2398;
    int a2399;
    int a2400;
    int a2401;
    int a2402;
    int a2403;
    int a2404;
    int a2405;
    int a2406;
    int a2407;
    int a2408;
    int a2409;
    int a2410;
    int a2411;
    int a2412;
    int a2413;
    dd_I a2414;
    dd_I a2415;
    dd_I a2416;
    dd_I a2417;
    dd_I s6510;
    dd_I s6511;
    dd_I s6512;
    dd_I s6513;
    dd_I t5622;
    dd_I t5623;
    dd_I t5624;
    dd_I t5625;
    dd_I t5626;
    dd_I t5627;
    dd_I t5628;
    dd_I t5629;
    dd_I t5630;
    dd_I t5631;
    dd_I t5632;
    dd_I t5633;
    dd_I t5634;
    dd_I t5635;
    dd_I t5636;
    dd_I t5637;
    dd_I t5638;
    dd_I t5639;
    dd_I t5640;
    dd_I t5641;
    dd_I t5642;
    dd_I t5643;
    dd_I t5644;
    dd_I t5645;
    dd_I t5646;
    dd_I t5647;
    dd_I t5648;
    dd_I t5649;
    a2398 = (2 * i837);
    a2399 = (a2398 + 1);
    a2400 = (a2398 + 64);
    a2401 = (a2398 + 65);
    t5622 = _ia_add_dd(*((T129 + a2398)), *((T129 + a2400)));
    t5623 = _ia_add_dd(*((T129 + a2399)), *((T129 + a2401)));
    t5624 = _ia_sub_dd(*((T129 + a2398)), *((T129 + a2400)));
    t5625 = _ia_sub_dd(*((T129 + a2399)), *((T129 + a2401)));
    a2402 = (a2398 + 32);
    a2403 = (a2398 + 33);
    a2404 = (a2398 + 96);
    a2405 = (a2398 + 97);
    t5626 = _ia_add_dd(*((T129 + a2402)), *((T129 + a2404)));
    t5627 = _ia_add_dd(*((T129 + a2403)), *((T129 + a2405)));
    t5628 = _ia_sub_dd(*((T129 + a2402)), *((T129 + a2404)));
    t5629 = _ia_sub_dd(*((T129 + a2403)), *((T129 + a2405)));
    t5630 = _ia_add_dd(t5622, t5626);
    t5631 = _ia_add_dd(t5623, t5627);
    t5632 = _ia_sub_dd(t5622, t5626);
    t5633 = _ia_sub_dd(t5623, t5627);
    t5634 = _ia_sub_dd(t5624, t5629);
    t5635 = _ia_add_dd(t5625, t5628);
    t5636 = _ia_add_dd(t5624, t5629);
    t5637 = _ia_sub_dd(t5625, t5628);
    a2406 = (a2398 + 16);
    a2407 = (a2398 + 17);
    a2408 = (a2398 + 80);
    a2409 = (a2398 + 81);
    t5638 = _ia_add_dd(*((T129 + a2406)), *((T129 + a2408)));
    t5639 = _ia_add_dd(*((T129 + a2407)), *((T129 + a2409)));
    t5640 = _ia_sub_dd(*((T129 + a2406)), *((T129 + a2408)));
    t5641 = _ia_sub_dd(*((T129 + a2407)), *((T129 + a2409)));
    a2410 = (a2398 + 48);
    a2411 = (a2398 + 49);
    a2412 = (a2398 + 112);
    a2413 = (a2398 + 113);
    t5642 = _ia_add_dd(*((T129 + a2410)), *((T129 + a2412)));
    t5643 = _ia_add_dd(*((T129 + a2411)), *((T129 + a2413)));
    t5644 = _ia_sub_dd(*((T129 + a2410)), *((T129 + a2412)));
    t5645 = _ia_sub_dd(*((T129 + a2411)), *((T129 + a2413)));
    t5646 = _ia_add_dd(t5638, t5642);
    t5647 = _ia_add_dd(t5639, t5643);
    t5648 = _ia_sub_dd(t5638, t5642);
    t5649 = _ia_sub_dd(t5639, t5643);
    dd_I _t53 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
    dd_I _t54 = _ia_sub_dd(t5640, t5645);
    a2414 = _ia_mul_dd(_t53, _t54);
    dd_I _t55 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
    dd_I _t56 = _ia_add_dd(t5641, t5644);
    a2415 = _ia_mul_dd(_t55, _t56);
    s6510 = _ia_sub_dd(a2414, a2415);
    s6511 = _ia_add_dd(a2414, a2415);
    dd_I _t57 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
    dd_I _t58 = _ia_add_dd(t5640, t5645);
    a2416 = _ia_mul_dd(_t57, _t58);
    dd_I _t59 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
    dd_I _t60 = _ia_sub_dd(t5641, t5644);
    a2417 = _ia_mul_dd(_t59, _t60);
    s6512 = _ia_add_dd(a2416, a2417);
    s6513 = _ia_sub_dd(a2416, a2417);
    *((Y + a2398)) = _ia_add_dd(t5630, t5646);
    *((Y + a2399)) = _ia_add_dd(t5631, t5647);
    *((Y + a2400)) = _ia_sub_dd(t5630, t5646);
    *((Y + a2401)) = _ia_sub_dd(t5631, t5647);
    *((Y + a2406)) = _ia_add_dd(t5634, s6510);
    *((Y + a2407)) = _ia_add_dd(t5635, s6511);
    *((Y + a2408)) = _ia_sub_dd(t5634, s6510);
    *((Y + a2409)) = _ia_sub_dd(t5635, s6511);
    *((Y + a2402)) = _ia_sub_dd(t5632, t5649);
    *((Y + a2403)) = _ia_add_dd(t5633, t5648);
    *((Y + a2404)) = _ia_add_dd(t5632, t5649);
    *((Y + a2405)) = _ia_sub_dd(t5633, t5648);
    *((Y + a2410)) = _ia_sub_dd(t5636, s6512);
    *((Y + a2411)) = _ia_add_dd(t5637, s6513);
    *((Y + a2412)) = _ia_add_dd(t5636, s6512);
    *((Y + a2413)) = _ia_sub_dd(t5637, s6513);
  }
}
