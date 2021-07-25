double f(double arg, double guess) {
//    double x = guess - (guess*guess*guess-arg)/(arg*guess*guess);
    double x = guess*(1-1/arg)+1/(guess*guess);
    for(int i = 0; i < 20; ++i) {
//        x = x - (x*x*x - arg)/(arg*x*x);
        x = x*(1-1/arg)+1/(x*x);
    }
    return x;
}
