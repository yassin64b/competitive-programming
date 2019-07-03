#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long f(long long x, long long c) {
    return x / c;
}

long long f(long long a, long long b, long long c) {
    return f(b, c) - f(a - 1, c);
}


int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    long long lcmcd = lcm(C, D);

    cout << (B - A + 1) - (f(A, B, C) + f(A, B, D) - f(A, B, lcmcd)) << "\n";

    return 0;
}