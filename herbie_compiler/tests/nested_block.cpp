int main() {
    double a = 5;
    {
        double a = 4;
        {
            double a = 3;
        }
    }
    return 0;
}
