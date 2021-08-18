double f(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double a = x1*y2 + x2*y3 + x3*y4 + x4*y1 - x2*y1 - x3*y2 - x4*y3 - x1*y4;
    if(a < 0) a = -a;
    return 0.5*a;
}
