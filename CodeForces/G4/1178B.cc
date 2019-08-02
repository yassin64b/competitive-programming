#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<vector<i64>> dp(n + 1, vector<i64>(4, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && s[i] == 'v' && s[i + 1] == 'v') {
            dp[i + 2][1] += dp[i][0];
            dp[i + 2][3] += dp[i][2];
        } else if (s[i] == 'o') {
            dp[i + 1][2] += dp[i][1];
        }
        for (int j = 0; j <= 3; ++j) {
            dp[i + 1][j] += dp[i][j];
        }
    }
    cout << dp[n][3] << "\n";

    return 0;
}