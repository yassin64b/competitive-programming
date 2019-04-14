#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int MOD = 998'244'353;

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

int fac(int k) {
    int res = 1;
    for (int j = 2; j <= k; ++j) {
        res = (i64)j * res % MOD;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, k, l;
    cin >> n >> k >> l;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(2 * n + 2,
                                   vector<int>(n + 1, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int x = 0; x <= 1; ++x) {
                if (j < n) { // open new seg
                    dp[x][i+1][j+1] = (dp[x][i+1][j+1] + dp[x][i][j]) % MOD;
                }
                if (j > 0) { // close any one open seg
                    dp[x][i+1][j-1] = (dp[x][i+1][j-1] + (i64)j * dp[x][i][j]) % MOD;
                }
            }
            if (j >= k) { // current point is covered by k segments
                dp[1][i+1][j] = (dp[1][i+1][j] + dp[0][i][j]) % MOD;
            }
        }
    }
    int cnt_ok = (i64)l * dp[1][2 * n + 1][0] % MOD;
    int cnt_total = fac(2 * n + 1);
    int cnt_perm = fac(n);
    int cnt_swap = modPow(2, n);

    int res = (i64)cnt_ok * cnt_perm % MOD * (i64)cnt_swap % MOD * (i64)modPow(cnt_total) % MOD;
    cout << res << "\n";

    return 0;
}