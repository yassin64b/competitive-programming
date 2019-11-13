#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    const int n = s.size(), m = t.size();
    constexpr int INF = 5'000;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i < n) // add one char to s
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (j < m) // add one char to t
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            if (i < n && j < m) // replace char in s
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1],
                                       dp[i][j] + (s[i] != t[j]));
        }
    }
    cout << dp[n][m] << "\n";
    
    return 0;
}