int main() {
    double a = 100000.1;
    double b = 100000000.1;
    double c = 100.1;
    double D = b*b - 4.*a*c;
    double res = (-b + sqrt(D))/(2.0*a);
    return 0;
}
