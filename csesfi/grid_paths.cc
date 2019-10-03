#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    constexpr int MOD = 1'000'000'007;
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = (g[0][0] != '*');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + 1 < n && g[i + 1][j] != '*') {
                dp[i + 1][j] += dp[i][j];
                if (dp[i + 1][j] >= MOD) 
                    dp[i + 1][j] -= MOD;
            }
            if (j + 1 < n && g[i][j + 1] != '*') {
                dp[i][j + 1] += dp[i][j];
                if (dp[i][j + 1] >= MOD) 
                    dp[i][j + 1] -= MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}