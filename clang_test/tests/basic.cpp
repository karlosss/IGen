int main() {
    double a, b, c, d;
    a = 1 + 2.5;
    b = 42 + 69;

    if(..) {
        b = 2;

    }
    else {

    }

    fn(a+b+c);



    c = a + b; // 1 + 2.5 + b
    a = c + 5; // 1 + 2.5 + b + 5
    a = a + b; // 1 + 2.5 + b + 5 + b
    return 0;
}
