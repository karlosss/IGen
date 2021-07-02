#include "igen_lib.h"
#include "igen_math.h"
#include <fenv.h>
#include <iostream>

int main() {
    fesetround(FE_UPWARD);
  f64_I a = {-2.0, 2.0};
  f64_I b = {10.0, -10.0};
  f64_I c = {-3.0, 3.0};
  f64_I _t1 = _ia_set_f64(-4.0, 4.0);
  f64_I _t2 = _ia_mul_f64(_t1, a);
  f64_I _t3 = _ia_mul_f64(b, b);
  f64_I _t4 = _ia_mul_f64(_t2, c);
  f64_I D = _ia_sub_f64(_t3, _t4);
  f64_I _t5 = _ia_neg_f64(b);
  f64_I _t6 = _ia_sqrt_f64(D);
  f64_I _t7 = _ia_set_f64(-2.0, 2.0);
  f64_I _t8 = _ia_add_f64(_t5, _t6);
  f64_I _t9 = _ia_mul_f64(_t7, a);
  f64_I res = _ia_div_f64(_t8, _t9);
    std::cout << "interval: " << res.lo << " " << res.up << ", width: " << res.lo + res.up << ", relwidth: " << (res.lo + res.up) / ((-res.lo + res.up)/2.0) << "\n";
  return 0;
}
