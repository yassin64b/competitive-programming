#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int q;
    cin >> q;
    for (int qq = 0; qq < q; ++qq) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        constexpr i64 INF = 1e18;
        vector<vector<i64>> dp(n, vector<i64>(3, INF));
        dp[0][0] = 0;
        dp[0][1] = b[0];
        dp[0][2] = 2 * b[0];
        for (int i = 1; i < n; ++i) {
            for (int j1 = 0; j1 <= 2; ++j1) {
                for (int j2 = 0; j2 <= 2; ++j2) {
                    if (a[i - 1] + j1 != a[i] + j2) {
                        dp[i][j2] = min(dp[i][j2],
                                        dp[i - 1][j1] + j2 * b[i]);
                    }
                }
            }
        }
        cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << "\n";
    }
    return 0;
}