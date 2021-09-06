double sqrt(double);
double pow(double, double)

double f(double a, double b, double c, double d) {
    return (-(b*b*b)/(27*a*a*a) + (b*c)/(6*a*a) - d/(2*a)) + sqrt( pow(-(b*b*b)/(27*a*a*a) + (b*c)/(6*a*a) - d/(2*a), 2) + pow(c/(3*a)-(b*b)/(9*a*a), 3) );
}
