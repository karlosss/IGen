#include "igen_lib.h"
#include "igen_math.h"
#include <fenv.h>
#include <iostream>

int main() {
    fesetround(FE_UPWARD);
  f64_I x = {-1.0999999999999999, 1.1000000000000003};
  f64_I _t1 = _ia_mul_f64(x, x);
  f64_I _t2 = _ia_mul_f64(_t1, x);
  f64_I _t3 = _ia_mul_f64(_t2, x);
  f64_I _t4 = _ia_mul_f64(_t3, x);
  f64_I _t5 = _ia_mul_f64(_t4, x);
  f64_I _t6 = _ia_mul_f64(_t5, x);
  f64_I _t7 = _ia_mul_f64(_t6, x);
  f64_I _t8 = _ia_mul_f64(_t7, x);
  f64_I _t9 = _ia_mul_f64(_t8, x);
  f64_I _t10 = _ia_mul_f64(_t9, x);
  f64_I _t11 = _ia_mul_f64(_t10, x);
  f64_I _t12 = _ia_mul_f64(_t11, x);
  f64_I _t13 = _ia_mul_f64(_t12, x);
  f64_I _t14 = _ia_mul_f64(_t13, x);
  f64_I _t15 = _ia_mul_f64(_t14, x);
  f64_I _t16 = _ia_mul_f64(_t15, x);
  f64_I _t17 = _ia_mul_f64(_t16, x);
  f64_I _t18 = _ia_mul_f64(_t17, x);
  f64_I _t19 = _ia_mul_f64(_t18, x);
  f64_I _t20 = _ia_mul_f64(_t19, x);
  f64_I _t21 = _ia_mul_f64(_t20, x);
  f64_I _t22 = _ia_mul_f64(_t21, x);
  f64_I _t23 = _ia_mul_f64(_t22, x);
  f64_I _t24 = _ia_mul_f64(_t23, x);
  f64_I _t25 = _ia_mul_f64(_t24, x);
  f64_I _t26 = _ia_mul_f64(_t25, x);
  f64_I _t27 = _ia_mul_f64(_t26, x);
  f64_I _t28 = _ia_mul_f64(_t27, x);
  f64_I res = _ia_mul_f64(_t28, x);
    std::cout << "interval: " << res.lo << " " << res.up << ", width: " << res.lo + res.up << ", relwidth: " << (res.lo + res.up) / ((-res.lo + res.up)/2.0) << "\n";
  return 0;
}
