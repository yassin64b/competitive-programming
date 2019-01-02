// get modular inverse for prime MOD with call modPow(a, MOD - 2, MOD)
int modPow(int a, int b, int c = MOD) {
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b /= 2;
    }
    return x % c;
}

long long inv(long long a, long long b) {
    return (1 < a) ? b - inv(b % a, a) * b / a : 1;
}