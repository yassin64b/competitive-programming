#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> T[i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 1));
    constexpr int MOD = 1'000'000'007;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]) % MOD;
            if (S[i-1] == T[j-1]) 
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
    }
    cout << dp[N][M] << "\n";

    return 0;
}