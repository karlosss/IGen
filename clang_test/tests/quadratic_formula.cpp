double f(double a, double b, double c) {
    double D = b*b - 4.*a*c;
    double res = (-b + sqrt(D))/(2.0*a);
    return res;
}
