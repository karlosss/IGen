double f(double arg, double guess) {
    double x = guess - (guess*guess*guess-arg)/(arg*guess*guess);
    for(int i = 0; i < 20; ++i) {
        x = x - (x*x*x - arg)/(arg*x*x);
    }
    return x;
}
