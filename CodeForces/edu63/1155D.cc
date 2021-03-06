#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    vector<vector<i64>> dp(n + 1, vector<i64>(3, 0));
    // dp[i][0] = mx with no multiplied part
    // dp[i][1] = mx with cur active multiply part
    // dp[i][2] = mx with finished multiply part
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = max(dp[i + 1][0], a[i] + dp[i][0]);

        dp[i + 1][1] = max(dp[i + 1][1], x * a[i] + dp[i][0]);
        dp[i + 1][1] = max(dp[i + 1][1], x * a[i] + dp[i][1]);

        dp[i + 1][2] = max(dp[i + 1][2], a[i] + dp[i][1]);
        dp[i + 1][2] = max(dp[i + 1][2], a[i] + dp[i][2]);
    }
    i64 mx = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << "\n";

    return 0;
}