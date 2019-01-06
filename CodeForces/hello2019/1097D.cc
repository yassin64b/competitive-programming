#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int MOD = 1'000'000'007;

int mod_pow(int a, int b, int c = MOD) {
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

void calc_dp(i64 p, i64 &n, int &res, int k) {
    int m = 0;
    while (n % p == 0) {
        n /= p;
        ++m;
    }
    vector<vector<int>> dp(k + 1, vector<int>(m + 1, 0));
    dp[0][m] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= m; ++j) {
            int div_inv = mod_pow(j + 1, MOD - 2);
            for (int l = 0; l <= j; ++l) {
                dp[i + 1][l] = (dp[i + 1][l] + 1LL * dp[i][j] * div_inv) % MOD;
            }
        }
    }
    int exp_v = 0;
    i64 cur_p = 1;
    for (int j = 0; j <= m; ++j) {
        exp_v = (exp_v + dp[k][j] * cur_p) % MOD;
        cur_p = (cur_p * p) % MOD;
    }
    res = (1LL * res * exp_v) % MOD;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    i64 n;
    int k;
    cin >> n >> k;
    int res = 1;
    for (i64 p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            calc_dp(p, n, res, k);
        }
    }

    if (n > 1) {
        calc_dp(n, n, res, k);
    }

    cout << res << "\n";


    return 0;
}