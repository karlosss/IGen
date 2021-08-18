double f(double x) {
    return sqrt(x*x+1.0);
}

double f2(double x) {
    if(x <= 324.45){
        return sqrt(x*x+1.0);
    }
    return x + 0.5/x - 0.125/(x*x*x);
}
