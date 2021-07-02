#include "igen_lib.h"
f64_I solve_plus(f64_I a, f64_I b, f64_I c) {
  f64_I D;
  f64_I r1;
  f64_I _t1 = _ia_set_f64((1.0), (-1.0));
  f64_I _t2 = _ia_add_f64(b, _t1);
  f64_I _t3 = _ia_div_f64(a, _t2);
  f64_I _t4 = _ia_set_f64((-4.0), (4.0));
  f64_I _t5 = _ia_div_f64(b, _t3);
  f64_I _t6 = _ia_mul_f64(_t4, c);
  f64_I _t7 = _ia_sub_f64(_t5, _t6);
  f64_I _t8 = _ia_set_f64((-2.0), (2.0));
  f64_I _ret;
  _ret = _ia_div_f64(_t7, _t8);
  return _ret;
}

f64_I solve_minus(f64_I a, f64_I b, f64_I c) {
  f64_I D;
  f64_I r1;
  f64_I _t9 = _ia_set_f64((-4.0), (4.0));
  f64_I _t10 = _ia_set_f64((1.0), (-1.0));
  f64_I _t11 = _ia_sub_f64(_t10, b);
  f64_I _t12 = _ia_div_f64(_t11, a);
  f64_I _t13 = _ia_mul_f64(_t9, c);
  f64_I _t14 = _ia_mul_f64(b, _t12);
  f64_I _t15 = _ia_add_f64(_t13, _t14);
  f64_I _t16 = _ia_set_f64((-2.0), (2.0));
  f64_I _ret;
  _ret = _ia_div_f64(_t15, _t16);
  return _ret;
}

int main() {
  f64_I a;
  a = _ia_set_f64(-10000000000000.0, 10000000000000.0);
  f64_I b;
  b = _ia_set_f64(-10000000000000000.0, 10000000000000000.0);
  f64_I c;
  c = _ia_set_f64(-1e+19.0, 1e+19.0);
  f64_I res1;
  res1 = solve_plus(a, b, c);
  f64_I res2;
  res2 = solve_minus(a, b, c);
  return 0;
}
