#include "igen_lib.h"
#include "igen_math.h"
#include <fenv.h>
#include <iostream>

f64_I f(f64_I x) {
  f64_I _t1 = _ia_mul_f64(x, x);
  f64_I _t2 = _ia_set_f64(-1.0, 1.0);
  f64_I _t3 = _ia_add_f64(_t1, _t2);
  f64_I _ret;
  _ret = _ia_sqrt_f64(_t3);
  return _ret;
}

f64_I f2(f64_I x) {
  f64_I _t4 = _ia_set_f64(-324.44999999999993, 324.45000000000005);
  if (_ia_cmple_f64(x, _t4)) {
    f64_I _t5 = _ia_mul_f64(x, x);
    f64_I _t6 = _ia_set_f64(-1.0, 1.0);
    f64_I _t7 = _ia_add_f64(_t5, _t6);
    f64_I _ret;
    _ret = _ia_sqrt_f64(_t7);
    return _ret;
  }
  f64_I _t8 = _ia_set_f64(-0.5, 0.5);
  f64_I _t9 = _ia_div_f64(_t8, x);
  f64_I _t10 = _ia_mul_f64(x, x);
  f64_I _t11 = _ia_set_f64(-0.125, 0.125);
  f64_I _t12 = _ia_mul_f64(_t10, x);
  f64_I _t13 = _ia_add_f64(x, _t9);
  f64_I _t14 = _ia_div_f64(_t11, _t12);
  f64_I _ret;
  _ret = _ia_sub_f64(_t13, _t14);
  return _ret;
}

int main() {
    fesetround(FE_UPWARD);
    std::cout.precision(30);
    f64_I in = _ia_set_f64(-1e50, 1e50);
    f64_I out = f(in);
    f64_I out2 = f2(in);
    std::cout << -out.lo << " " << out.up << std::endl;
    std::cout << -out2.lo << " " << out2.up << std::endl;
    return 0;
}