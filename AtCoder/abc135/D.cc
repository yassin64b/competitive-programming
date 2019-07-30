#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();
    reverse(begin(S), end(S));

    constexpr int MOD = 1'000'000'007;
    vector<vector<int>> dp(n + 1, vector<int>(13, 0));
    dp[0][0] = 1;
    for (int i = 0, mul = 1; i < n; ++i) {
        for (int j = 0; j < 13; ++j) {
            if (S[i] == '?') {
                for (int dig = 0; dig < 10; ++dig) {
                    int nj = (j + mul * dig) % 13;
                    dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j]) % MOD;
                }
            } else {
                int dig = S[i] - '0';
                int nj = (j + mul * dig) % 13;
                dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j]) % MOD;
            }
        }
        mul = mul * 10 % 13;
    }
    
    cout << dp[n][5] << "\n";

    return 0;
}