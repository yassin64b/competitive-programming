#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

int mod_pow(int a, int b, int c) {
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
int mod_inv(int a) {
    return mod_pow(a, MOD - 2, MOD);
}
int choose(int n, int k, const vector<int> &fac) {
    if (k > n) return 0;
    return 1LL * fac[n] * mod_inv(1LL * fac[k] * fac[n - k] % MOD) % MOD;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    const int mx = max(n, m);
    vector<int> fac(mx + 1, 1);
    for (int i = 2; i <= mx; ++i) {
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    }
    vector<int> npow(n, 1), mpow(n, 1);
    for (int i = 1; i < n; ++i) {
        npow[i] = 1LL * npow[i - 1] * n % MOD;
        mpow[i] = 1LL * mpow[i - 1] * m % MOD;
    }

    int res = 0;
    for (int k = 1; k <= n - 1; ++k) {
        // choose k - 1 vertices for the path from a to b
        int cur = choose(n - 2, k - 1, fac);
        // allow every permutation of the path
        cur = 1LL * cur * fac[k - 1] % MOD;

        // general cayley's formula to add k disjoint trees
        cur = 1LL * cur * (k + 1) % MOD;
        if (n == k + 1) cur = 1LL * cur * mod_inv(n) % MOD;
        else cur = 1LL * cur * npow[n - k - 2] % MOD;

        // stars-and-bars to let weight on path sum to m
        cur = 1LL * cur * choose(m - 1, k - 1, fac) % MOD;

        // choose other weights arbitrarily
        cur = 1LL * cur * mpow[n - 1 - k] % MOD;

        res = (res + cur) % MOD;
    }
    cout << res << "\n";

    return 0;
}