#include <bits/stdc++.h>

using namespace std;

int recurse(int a, int b, vector<vector<int>> &dp, int INF) {
    int &res = dp[a][b];
    if (res != INF) {
        return res;
    } else if (a == b) {
        return (res = 0);
    }
    for (int c = 1; c < a; ++c) {
        res = min(res, recurse(c, b, dp, INF) + recurse(a - c, b, dp, INF) + 1);
    }
    for (int c = 1; c < b; ++c) {
        res = min(res, recurse(a, c, dp, INF) + recurse(a, b - c, dp, INF) + 1);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    const int INF = (a + 1) * (b + 1);
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INF));
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << "\n";
    //cout << recurse(a, b, dp, INF) << "\n";

    return 0;
}