int main() {
    double a = 1e20;
    double b = 1e100;
    double c = 1e50;
    double D = b*b - 4.*a*c;
    double res = (-b + sqrt(D))/(2.0*a);
    return 0;
}
