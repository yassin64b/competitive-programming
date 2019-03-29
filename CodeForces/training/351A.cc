#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<double> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    } 
    constexpr double INF = 1e18;
    vector<vector<double>> dp(2 * n + 1, vector<double>(2 * n + 1, INF));
    dp[0][0 + n] = 0;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = -n; j <= n; ++j) {
            if (j > -n) {
                double v = dp[i][j + n] + a[i] - floor(a[i]);
                if (abs(v) < abs(dp[i + 1][j - 1 + n])) 
                    dp[i + 1][j - 1 + n] = v;
            }
            if (j < n) {
                double v = dp[i][j + n] + a[i] - ceil(a[i]);
                if (abs(v) < abs(dp[i + 1][j + 1 + n])) 
                    dp[i + 1][j + 1 + n] = v;
            }
        }
    }
    cout.precision(3);
    cout << fixed << abs(dp[2 * n][0 + n]) << "\n";

    return 0;
}