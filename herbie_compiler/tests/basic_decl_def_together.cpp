int main() {
    double a = 1 + 2.5;
    double b = 42 + 69;
    double c = a + b; // 1 + 2.5 + b
    a = c + 5; // 1 + 2.5 + b + 5
    a = a + b; // 1 + 2.5 + b + 5 + b
    return 0;
}
