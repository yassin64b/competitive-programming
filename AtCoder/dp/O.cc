#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    const int m = (1 << N);
    vector<int> dp(m, 0);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int mask = m - 1; mask >= 0; --mask) {
            if (dp[mask]) {
                for (int j = 0; j < N; ++j) {
                    if (mask & (1 << j)) {
                        continue;
                    }
                    if (a[i][j]) {
                        int new_mask = mask | (1 << j);
                        dp[new_mask] = (dp[new_mask] + dp[mask]);
                        if (dp[new_mask] >= MOD) {
                            dp[new_mask] -= MOD;
                        }
                    }
                }
                dp[mask] = 0;
            }
        }
    }
    cout << dp[m - 1] << "\n";


    return 0;
}