#include "igen_lib.h"
#include "igen_math.h"
#include <fenv.h>
#include <iostream>

f64_I artcomp2(f64_I x, f64_I y) {
  f64_I _t1 = _ia_mul_f64(x, x);
  f64_I _t2 = _ia_mul_f64(y, y);
  f64_I _t3 = _ia_add_f64(_t1, _t2);
  f64_I _t4 = _ia_sqrt_f64(_t3);
  f64_I _t5 = _ia_set_f64(-2.0, 2.0);
  f64_I _t6 = _ia_add_f64(_t4, x);
  f64_I _t7 = _ia_mul_f64(_t5, _t6);
  f64_I _t8 = _ia_set_f64(-0.5, 0.5);
  f64_I _t9 = _ia_sqrt_f64(_t7);
  f64_I _ret;
  _ret = _ia_mul_f64(_t8, _t9);
  return _ret;
}

int main() {
    fesetround(FE_UPWARD);
  f64_I _t10 = _ia_set_f64(10.100000000000001, -10.099999999999998);
  f64_I _t11 = _ia_set_f64(-2.0999999999999996, 2.1000000000000005);
  f64_I res = artcomp2(_t10, _t11);
    std::cout << "interval: " << -res.lo << " " << res.up << ", width: " << res.lo + res.up << ", relwidth: " << -log2(-(res.lo + res.up) / ((-res.lo + res.up)/2.0)) << "\n";
  return 0;
}
