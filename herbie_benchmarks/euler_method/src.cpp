double f(double arg, double step, double initx, double inity) {
    // f' = 3x^3 + 6x^2 + 8x
    double x = initx;
    double y = inity;
    while(x < arg) {
        y = y + step*(3*x*x*x+6*x*x+8*x);
        x = x + step;
    }
    return y;
}
