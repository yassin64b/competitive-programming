#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

int modPow(int a, int b = MOD - 2, int c = MOD) {
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
int ncr(int n, int k, const vector<int> &fac) {
    return 1LL * fac[n] * modPow(1LL * fac[k] * fac[n - k] % MOD) % MOD;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int H, W, A, B;
    cin >> H >> W >> A >> B;
    constexpr int MX = 400'000;
    vector<int> fac(MX + 1, 1);
    for (int i = 2; i <= MX; ++i) {
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    }
    int res = 0;
    for (int hi = 0; hi < H - A; ++hi) {
        int c1 = ncr(hi + B - 1, hi, fac);
        int c2 = ncr(H - 1 - hi + W - B - 1, H - 1 - hi, fac);
        res = (res + 1LL * c1 * c2) % MOD;
    }
    cout << res << "\n";

    return 0;
}