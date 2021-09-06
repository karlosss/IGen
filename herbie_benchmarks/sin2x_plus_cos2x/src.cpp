double f(double x) {
    double sinx = x - (x*x*x)/6. + (x*x*x*x*x)/120. - (x*x*x*x*x*x*x)/5040.;
    double cosx = 1 - (x*x)/2 + (x*x*x*x)/24 - (x*x*x*x*x*x)/720;
    return sinx * sinx + cosx * cosx;
}
