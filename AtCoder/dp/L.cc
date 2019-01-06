#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<i64, i64>>> dp(N, vector<pair<i64, i64>>(N, {0, 0}));
    for (int i = 0; i < N; ++i) {
        dp[i][i].first = a[i];
        dp[i][i].second = -a[i];
    }
    for (int d = 1; d < N; ++d) {
        for (int i = 0; i < N; ++i) {
            int j = i + d;
            if (j < N) {
                dp[i][j].first = max(dp[i + 1][j].second + a[i], dp[i][j - 1].second + a[j]);
                dp[i][j].second = min(dp[i + 1][j].first - a[i], dp[i][j - 1].first - a[j]);
            }
        }
    }
    cout << dp[0][N - 1].first << "\n";

    return 0;
}