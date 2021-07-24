#include "igen_lib.h"
#include "igen_math.h"
#include <fenv.h>
#include <iostream>
#include <mpfr.h>
#include <cfloat>
#include <cstring>
#include <string>

static const unsigned mpfr_high_precision = 500;


void print_double(double d) {
    uint64_t u;
    memcpy(&u, &d, sizeof(d));
    std::cout << std::hex << u << "\n";
}


static double getCorrectBits(mpfr_t& xl, mpfr_t& xu, unsigned precision) {
    double r, incorrect_bits_d;
    mpfr_t delta, ulp_xl, next_xl, delta_in_ulps, incorrect_bits;

    /* Init variables */
    mpfr_init2(delta, mpfr_high_precision);
    mpfr_init2(ulp_xl, mpfr_high_precision);
    mpfr_init2(next_xl, precision);
    mpfr_init2(delta_in_ulps, mpfr_high_precision);
    mpfr_init2(incorrect_bits, mpfr_high_precision);

    /* Determine delta = xu - xl */
    mpfr_sub(delta, xu, xl, MPFR_RNDU);

    /* Determine ulp(xl) */
    mpfr_set(next_xl, xl, MPFR_RNDU);
    mpfr_nextabove(next_xl);
    mpfr_sub(ulp_xl, next_xl, xl, MPFR_RNDU);

    /* Determine how many ulp(x) are inside delta, i.e. delta / ulp(x) and based on this the number of
     * incorrect bits */
    mpfr_div(delta_in_ulps, delta, ulp_xl, MPFR_RNDU);
//    std::cout << mpfr_get_d(delta_in_ulps, MPFR_RNDU) << "\n";
    mpfr_add_d(delta_in_ulps, delta_in_ulps, 1.0, MPFR_RNDU);

    mpfr_log2(incorrect_bits, delta_in_ulps, MPFR_RNDU);
    incorrect_bits_d = mpfr_get_d(incorrect_bits, MPFR_RNDU);

    /* Adjust to get number of correct bits instead */
    r = precision - incorrect_bits_d;

    if (mpfr_zero_p(delta)) {
        r = precision;
    }

    mpfr_clears(delta, ulp_xl, next_xl, delta_in_ulps, incorrect_bits, (mpfr_ptr) nullptr);

    return r;
}


static double getCorrectBits(f64_I _x) {
    const double accuracy_double = 53;
    double correct_bits;
    u_f64i x = {.v = _x};
    x.lo = -x.lo; // Restore lower bound to its real value

    /* Relative error does not make much sense if interval contains zero */
    if (x.lo <= 0 && 0 <= x.up) {
        return 0;
    }

    /* If the exponents of the endpoints are very different then all bits are lost */
    int exp_lo, exp_up;
    frexp(x.lo, &exp_lo);
    frexp(x.up, &exp_up);
    if (exp_up - exp_lo > 1) {
        return 0;
    }

    mpfr_t xl, xu;
    mpfr_init2(xl, mpfr_high_precision);
    mpfr_init2(xu, mpfr_high_precision);
    mpfr_set_d(xl, x.lo, MPFR_RNDD);
    mpfr_set_d(xu, x.up, MPFR_RNDU);
    correct_bits = getCorrectBits(xl, xu, (unsigned) accuracy_double);

    return correct_bits;
}

FUNCTION

double neg(const std::string & s) {
    if(s[0] == '-') {
        return std::stod(s.substr(1));
    }
    return std::stod("-" + s);
}

int main(int argc, char** argv) {
    fesetround(FE_UPWARD);
    std::cout.precision(20);

    BOUNDS_DECL
    F64I_DECL
    f64_I res = FUNCALL

    for(int i = 1; i < argc; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << -res.lo << " " << res.up << " ";
    std::cout << getCorrectBits(res) << "\n";
    return 0;
}
