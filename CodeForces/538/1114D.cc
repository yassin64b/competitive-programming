#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    constexpr int INF = 1'000'000'000;
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INF, INF}));
    for (int i = 0; i < n; ++i) {
        dp[i][i].first = dp[i][i].second = 0;
    }
    for (int len = 1; len < n; ++len) {
        for (int i = 0, j = i + len - 1; i < n && j < n; ++i, ++j) {
            if (i > 0) {
                dp[i - 1][j].first = min(dp[i - 1][j].first, 
                            dp[i][j].first + (c[i - 1] != c[i]));
                dp[i - 1][j].first = min(dp[i - 1][j].first, 
                            dp[i][j].second + (c[i - 1] != c[j]));
            }
            if (j + 1 < n) {
                dp[i][j + 1].second = min(dp[i][j + 1].second,
                            dp[i][j].first + (c[j + 1] != c[i]));
                dp[i][j + 1].second = min(dp[i][j + 1].second,
                            dp[i][j].second + (c[j + 1] != c[j]));
            }
        }
    }
    cout << min(dp[0][n - 1].first, dp[0][n - 1].second) << "\n";

    return 0;
}