double solve_plus(double a, double b, double c) {
    double D = b*b - 4.*a*c;
    double r1 = (-b + D)/(2.0*a);
    return r1;
}

double solve_minus(double a, double b, double c) {
    double D = b*b - 4*a*c;
    double r1 = (-b - D)/(2*a);
    return r1;
}

int main() {
    double a = 10;
    double b = 20;
    double c = 30;
    double res1 = solve_plus(a, b, c);
    double res2 = solve_minus(a, b, c);
    return 0;
}
