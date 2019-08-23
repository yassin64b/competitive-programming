#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr i64 INF = 1e16;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        vector<pair<i64, i64>> dp(n + 1);
        dp[0].first = b;
        dp[0].second = INF;
        for (int i = 0; i < n; ++i) {
            dp[i + 1].first = min(dp[i].first + a + b, 
                                  dp[i].second + 2 * a + b);
            dp[i + 1].second = min(dp[i].first + 2 * a + 2 * b,
                                   dp[i].second + a + 2 * b);
            if (s[i] == '1' || (i + 1 < n && s[i + 1] == '1')) {
                dp[i + 1].first = INF;
            }
        }
        cout << dp[n].first << "\n";
    }

    return 0;
}