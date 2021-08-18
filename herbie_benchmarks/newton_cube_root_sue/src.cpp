double f(double arg, double guess) {
    double x = guess*(1-1/arg)+1/(guess*guess);
    for(int i = 0; i < 20; ++i) {
        x = x*(1-1/arg)+1/(x*x);
    }
    return x;
}
