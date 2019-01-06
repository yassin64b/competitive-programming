#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string K;
    int D;
    cin >> K >> D;
    for (char &c : K) {
        c -= '0';
    }
    int n = K.size();
    constexpr int MOD = 1'000'000'007;
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(D, {0, 0}));
    dp[0][0] = {1, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < D; ++j) {
            int nj = (j + K[i]) % D;
            dp[i + 1][nj].first = (dp[i + 1][nj].first + dp[i][j].first) % MOD;
            for (int dig = 0; dig < K[i]; ++dig) {
                nj = (j + dig) % D;
                dp[i + 1][nj].second = (dp[i + 1][nj].second + dp[i][j].first) % MOD;
            }
            for (int dig = 0; dig < 10; ++dig) {
                nj = (j + dig) % D;
                dp[i + 1][nj].second = (dp[i + 1][nj].second + dp[i][j].second) % MOD;
            }
        }
    }
    cout << ((dp[n][0].first + dp[n][0].second - 1) % MOD + MOD) % MOD << "\n";

    return 0;
}