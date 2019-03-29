#include <bits/stdc++.h>

using namespace std;

void comp_ncr() {
    
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    constexpr int MOD = 1'000'000'007;

    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > h) {
            cout << 0 << "\n";
            return 0;
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            // close 1 seg
            if (j > 0 && a[i] + j == h) 
                dp[i + 1][j - 1] = (dp[i + 1][j - 1] + 1LL * dp[i][j] * j) % MOD;
            // open 1 seg
            if (j < n && a[i] + j + 1 == h) 
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            // close 1, open 1
            if (j > 0 && a[i] + j + 1 == h) 
                dp[i + 1][j] = (dp[i + 1][j] + 1LL * dp[i][j] * j) % MOD;
            // open 1, close 
            if (j < n && a[i] + j + 1 == h) 
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            // don't change segments
            if (a[i] + j == h) 
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
        }
    }
    cout << dp[n][0] << "\n";

    return 0;
}