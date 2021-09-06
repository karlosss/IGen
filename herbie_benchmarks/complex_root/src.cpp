double sqrt(double);

double f(double x, double y) {
    return (1./2.)*sqrt(2.*(sqrt(x*x+y*y)+x));
}
