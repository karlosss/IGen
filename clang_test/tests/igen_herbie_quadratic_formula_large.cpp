#include "igen_lib.h"
#include "igen_math.h"
#include <fenv.h>
#include <iostream>

int main() {
    fesetround(FE_UPWARD);
  f64_I a;
  a = _ia_set_f64(-1e+20, 1e+20);
  f64_I b;
  b = _ia_set_f64(-9.9999999999999982e+99, 1.0000000000000002e+100);
  f64_I c;
  f64_I D;
  f64_I res;
  f64_I _t1 =
      _ia_set_f64((9.9844266336474407e-172), (-9.9844266336474384e-172));
  f64_I _t2 = _ia_set_f64((-4.0), (4.0));
  f64_I _t3 = _ia_mul_f64(_t2, a);
  f64_I _t4 =
      _ia_set_f64((-9.9999999999999987e+49), (1.0000000000000003e+50));
  f64_I _t5 = _ia_mul_f64(b, b);
  f64_I _t6 = _ia_mul_f64(_t3, _t4);
  f64_I _t7 = _ia_sub_f64(_t5, _t6);
  f64_I _t8 = _ia_set_f64((-2.0), (2.0));
  f64_I _t9 = _ia_sqrt_f64(_t7);
  f64_I _t10 = _ia_mul_f64(a, _t8);
  f64_I _t11 = _ia_set_f64((-2.0), (2.0));
  f64_I _t12 = _ia_mul_f64(a, _t11);
  f64_I _t13 = _ia_div_f64(_t9, _t10);
  f64_I _t14 = _ia_div_f64(b, _t12);
  f64_I _t15 = _ia_set_f64((-4.0), (4.0));
  f64_I _t16 = _ia_set_f64((-4.0), (4.0));
  f64_I _t17 = _ia_mul_f64(_t16, a);
  f64_I _t18 =
      _ia_set_f64((-9.9999999999999987e+49), (1.0000000000000003e+50));
  f64_I _t19 = _ia_mul_f64(b, b);
  f64_I _t20 = _ia_mul_f64(_t17, _t18);
  f64_I _t21 = _ia_sub_f64(_t19, _t20);
  f64_I _t22 = _ia_sqrt_f64(_t21);
  f64_I _t23 =
      _ia_set_f64((-9.9999999999999987e+49), (1.0000000000000003e+50));
  f64_I _t24 = _ia_add_f64(b, _t22);
  f64_I _t25 = _ia_div_f64(_t23, _t24);
  f64_I _t26 = _ia_set_f64((-2.0), (2.0));
  f64_I _t27 = _ia_neg_f64(_t15);
  f64_I _t28 = _ia_div_f64(_t25, _t26);
  f64_I _t29 = _ia_sub_f64(_t13, _t14);
  f64_I _t30 = _ia_mul_f64(_t27, _t28);
  res = (_ia_cmple_f64(b, _t1)) ? _t29 : _t30;
    std::cout << "interval: " << -res.lo << " " << res.up << ", width: " << res.lo + res.up << ", relwidth: " << -log2(-(res.lo + res.up) / ((-res.lo + res.up)/2.0)) << "\n";
  return 0;
}
