#include <bits/stdc++.h>

using namespace std;

int modPow(int a, int b, int c) {
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

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    const int SUM = n * (n + 1) / 2;
    if (SUM % 2) {
        cout << 0 << "\n";
        return 0;
    }
    const int MX = SUM / 2;
    constexpr int MOD = 1'000'000'007;
    vector<int> dp(MX + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = MX - i; j >= 0; --j) {
            dp[i + j] = (dp[i + j] + dp[j]) % MOD;
        }
    }
    cout << (1LL * dp[MX] * modPow(2, MOD - 2, MOD)) % MOD << "\n";

    return 0;
}