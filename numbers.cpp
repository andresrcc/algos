int gcd(int a, int b) {
    while (a && b) {
        if (a >= b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
