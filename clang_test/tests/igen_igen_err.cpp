#include "igen_lib.h"
#include "igen_math.h"

f64_I f(f64_I x) {
  f64_I _t1 =
      _ia_set_f64(1.3389308533534317e+154, -1.3389308533534314e+154);
  f64_I _t2 =
      _ia_set_f64(-5.6088274172049363e+153, 5.6088274172049378e+153);
  int _t3 = (_ia_cmple_f64(x, _t1));
  int _t4 = (!(_ia_cmple_f64(x, _t2)));
  f64_I _t5 = _ia_set_f64(-1.0, 1.0);
  f64_I _t6 = _ia_set_f64(-1.0, 1.0);
  f64_I _t7 = _ia_sub_f64(x, _t5);
  f64_I _t8 = _ia_set_f64(-2.0, 2.0);
  f64_I _t9 = _ia_div_f64(_t6, _t7);
  f64_I _t10 = _ia_div_f64(_t8, x);
  f64_I _t11 = _ia_sub_f64(_t9, _t10);
  f64_I _t12 = _ia_set_f64(-2.0, 2.0);
  f64_I _t13 = _ia_set_f64(-1.0, 1.0);
  f64_I _t14 = _ia_set_f64(-1.0, 1.0);
  f64_I _t15 = _ia_add_f64(x, _t13);
  f64_I _t16 = _ia_set_f64(-1.0, 1.0);
  f64_I _t17 = _ia_set_f64(-1.0, 1.0);
  f64_I _t18 = _ia_add_f64(x, _t16);
  f64_I _t19 = _ia_div_f64(_t14, _t15);
  f64_I _t20 = _ia_div_f64(_t17, _t18);
  f64_I _t21 = pow(_t11, _t12);
  f64_I _t22 = _ia_mul_f64(_t19, _t20);
  f64_I _t23 = _ia_set_f64(-1.0, 1.0);
  f64_I _t24 = _ia_set_f64(-1.0, 1.0);
  f64_I _t25 = _ia_sub_f64(x, _t23);
  f64_I _t26 = _ia_set_f64(-2.0, 2.0);
  f64_I _t27 = _ia_div_f64(_t24, _t25);
  f64_I _t28 = _ia_div_f64(_t26, x);
  f64_I _t29 = _ia_set_f64(-1.0, 1.0);
  f64_I _t30 = _ia_set_f64(-1.0, 1.0);
  f64_I _t31 = _ia_add_f64(x, _t29);
  f64_I _t32 = _ia_sub_f64(_t27, _t28);
  f64_I _t33 = _ia_div_f64(_t30, _t31);
  f64_I _t34 = _ia_sub_f64(_t21, _t22);
  f64_I _t35 = _ia_sub_f64(_t32, _t33);
  f64_I _t36 = _ia_set_f64(-1.0, 1.0);
  f64_I _t37 = _ia_set_f64(-1.0, 1.0);
  f64_I _t38 = _ia_set_f64(-1.0, 1.0);
  f64_I _t39 = _ia_sub_f64(x, _t38);
  f64_I _t40 = _ia_set_f64(-2.0, 2.0);
  f64_I _t41 = _ia_mul_f64(x, _t37);
  f64_I _t42 = _ia_mul_f64(_t39, _t40);
  f64_I _t43 = _ia_add_f64(x, _t36);
  f64_I _t44 = _ia_sub_f64(_t41, _t42);
  f64_I _t45 = _ia_set_f64(-1.0, 1.0);
  f64_I _t46 = _ia_sub_f64(x, _t45);
  f64_I _t47 = _ia_set_f64(-1.0, 1.0);
  f64_I _t48 = _ia_mul_f64(x, _t46);
  f64_I _t49 = _ia_mul_f64(_t43, _t44);
  f64_I _t50 = _ia_mul_f64(_t47, _t48);
  f64_I _t51 = _ia_set_f64(-1.0, 1.0);
  f64_I _t52 = _ia_set_f64(-1.0, 1.0);
  f64_I _t53 = _ia_sub_f64(x, _t52);
  f64_I _t54 = _ia_add_f64(x, _t51);
  f64_I _t55 = _ia_mul_f64(x, _t53);
  f64_I _t56 = _ia_add_f64(_t49, _t50);
  f64_I _t57 = _ia_mul_f64(_t54, _t55);
  f64_I _t58 = _ia_div_f64(_t34, _t35);
  f64_I _t59 = _ia_div_f64(_t56, _t57);
  f64_I _ret;
  _ret = (_ia_or_tb(_t3, _t4)) ? _t58 : _t59;
  return _ret;
}
