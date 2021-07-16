import decimal
import fractions
from math import log2, log10


class InexactResult(Exception):
    pass


def _strip_zeros(x_or_s):
    """strip excessive zeros from the end of decimal part and beginning from the integral part"""
    s = str(x_or_s).upper()
    if "." not in s and "E" not in s:
        integral = s.lstrip("0")
        if integral == "":
            integral = "0"
        return x_or_s.__class__(integral)
    elif "." in s and "E" not in s:
        integral, dec = s.split(".")
        integral = integral.lstrip("0")
        if integral == "":
            integral = "0"
        dec = dec.rstrip("0")
        if dec == "":
            return x_or_s.__class__(integral)
        else:
            return x_or_s.__class__(integral + "." + dec)
    elif "." not in s and "E" in s:
        integral, exp = s.split("E")
        integral = integral.lstrip("0")
        if integral == "":
            integral = "0"
        return x_or_s.__class__(integral + "E" + exp)
    else:
        num, exp = s.split("E")
        integral, dec = num.split(".")
        integral = integral.lstrip("0")
        if integral == "":
            integral = "0"
        dec = dec.rstrip("0")
        if dec == "":
            return x_or_s.__class__(integral + "E" + exp)
        else:
            return x_or_s.__class__(integral + "." + dec + "E" + exp)



def _split(x_or_s):
    """:returns (integral, decimal, exp) as strings"""
    x_or_s = _strip_zeros(x_or_s)
    s = str(x_or_s).upper()
    if "." in s and "E" in s:
        integral, r = s.split(".")
        dec, exp = r.split("E")
        exp = int(exp)
    elif "." in s and "E" not in s:
        integral, dec = s.split(".")
        exp = 0
    elif "." not in s and "E" in s:
        integral, exp = s.split("E")
        exp = int(exp)
        dec = ""
    else:
        integral = s
        exp = 0
        dec = ""

    return integral, dec, exp


def _get_prec(x):
    """returns how much precision is contained in Decimal"""
    integral, dec, exp = _split(x)

    if exp == 0:
        return len(integral) + len(dec)
    elif exp < 0:
        return len(dec) - exp + min(len(integral) + exp, 1)
    else:
        return len(integral) + exp + min(len(dec) - exp, 0)


def _expand_exp(x):
    integral, dec, exp = _split(x)
    if exp == 0:
        return x
    elif exp > 0:
        dec += abs(exp)*"0"
        integral = integral + dec[:exp]
        dec = dec[exp:]
        return _strip_zeros(decimal.Decimal(integral + "." + dec))
    else:
        integral = abs(exp)*"0" + integral
        dec = integral[exp:] + dec
        integral = integral[:exp].lstrip("0")
        if integral == "":
            integral = "0"
        return _strip_zeros(integral + "." + dec)


def _is_div_exact(denom):
    while denom != 1:
        if denom % 5 == 0:
            denom = denom // 5
        elif denom % 2 == 0:
            denom = denom // 2
        else:
            return False
    return True


def add(a, b):
    decimal.getcontext().prec = max(_get_prec(a), _get_prec(b)) + 1
    return a + b


def sub(a, b):
    decimal.getcontext().prec = max(_get_prec(a), _get_prec(b)) + 1
    return a - b


def mul(a, b):
    decimal.getcontext().prec = _get_prec(a) + _get_prec(b)
    return a * b


def div(a, b):
    _a = _expand_exp(a)
    _b = _expand_exp(b)
    integral_a, dec_a, _ = _split(_a)
    integral_b, dec_b, _ = _split(_b)
    if len(dec_a) > len(dec_b):
        num = integral_a + dec_a
        denom = integral_b + dec_b + (len(dec_a)-len(dec_b))*"0"
    else:
        num = integral_a + dec_a + (len(dec_b)-len(dec_a))*"0"
        denom = integral_b + dec_b
    num = int(_strip_zeros(num))
    denom = int(_strip_zeros(denom))
    f = fractions.Fraction(num, denom)
    if not _is_div_exact(f.denominator):
        raise InexactResult
    decimal.getcontext().prec = int(log10(f.numerator))+1 + int(log2(f.denominator))+1
    return decimal.Decimal(f.numerator) / decimal.Decimal(f.denominator)


def sqrt(a):
    decimal.getcontext().prec = _get_prec(a)
    res = a.sqrt()
    if mul(res, res) != a:
        raise InexactResult
    return res


def cbrt(a):
    if a == decimal.Decimal("1"):
        return decimal.Decimal("1")
    elif a == decimal.Decimal("-1"):
        return decimal.Decimal("-1")
    else:
        raise NotImplementedError("cbrt of anything else than +/- 1 is not supported")


def pow(base, exp):
    if exp == decimal.Decimal("0.5"):
        return sqrt(base)
    if exp % 1 != 0:
        raise NotImplementedError("power to a non-integral exp is not supported")
    if exp < 0:
        raise NotImplementedError("power to a negative exp is not supported")
    tmp = base
    for _ in range(int(exp)):
        tmp = mul(tmp, base)
    return tmp
