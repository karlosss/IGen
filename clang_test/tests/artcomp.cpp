double artcomp1(double x) {
    return (1/(x-1)-2/x) + (1/(x+1));
}

double artcomp2(double x, double y) {
    return (1./2.)*sqrt(2.*(sqrt(x*x+y*y)+x));
}

int main() {
    double res1 = artcomp1(10);
    double res2 = artcomp1(10e10);
    double res3 = artcomp1(10e100);
    double res4 = artcomp1(-10);
    double res5 = artcomp1(-10e10);
    double res6 = artcomp1(-10e100);
    double res = artcomp2(-10.1, 2.1);
    return 0;
}
