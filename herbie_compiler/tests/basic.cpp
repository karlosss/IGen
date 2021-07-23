int main() {
    double a, b, c, d;
    a = 1 + 2.5;
    b = 42 + 69;
    c = a + b; // 1 + 2.5 + b
    a = c + 5; // 1 + 2.5 + b + 5
    a = a + b; // 1 + 2.5 + b + 5 + b
    return 0;
}
