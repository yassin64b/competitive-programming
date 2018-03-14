bool is_prime(long long x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

vector<int> prime(MXV + 1, 1);
prime[0] = prime[1] = 0;
for (int i = 2; i * i <= MXV; ++i) {
    if (prime[i]) {
        for (int j = i * i; j <= MXV; j += i) {
            prime[j] = 0;
        }
    }
}