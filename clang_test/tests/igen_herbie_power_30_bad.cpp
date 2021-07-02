#include "igen_lib.h"
#include "igen_math.h"
#include <fenv.h>
#include <iostream>

int main() {
    fesetround(FE_UPWARD);
  f64_I x;
  f64_I res;
  f64_I _t1 = _ia_set_f64((-1.0999999999999999), (1.1000000000000003));
  f64_I _t2 = _ia_set_f64(-30.0, 30.0);
  res = pow(_t1, _t2);
    std::cout << "interval: " << res.lo << " " << res.up << ", width: " << res.lo + res.up << ", relwidth: " << (res.lo + res.up) / ((-res.lo + res.up)/2.0) << "\n";
  return 0;
}
