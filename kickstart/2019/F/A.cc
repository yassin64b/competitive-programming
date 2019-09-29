#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        const int INF = N + 1, MX = 1000;
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(K + 1,
                                                vector<int>(MX + 1, INF)));
        for (int i = 1; i <= MX; ++i) {
            dp[0][0][i] = 1;
        }
        dp[0][0][A[0]] = 0;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j <= K; ++j) {
                int mn = INF;
                for (int v = 1; v <= MX; ++v) {
                    mn = min(mn, dp[i - 1][j][v]);
                }
                // change A[i] to v
                for (int v = 1; v <= MX; ++v) {
                    dp[i][j][v] = min(dp[i][j][v], dp[i - 1][j][v] + 1);
                }
                // don't change A[i]
                dp[i][j][A[i]] = min(dp[i][j][A[i]], dp[i - 1][j][A[i]]);
                // start new seg without change A[i]
                if (j < K) {
                    dp[i][j + 1][A[i]] = min(dp[i][j + 1][A[i]], mn);
                }
                // start new seg with change A[i]
                if (j < K) {
                    for (int v = 1; v <= MX; ++v) {
                        dp[i][j + 1][v] = min(dp[i][j + 1][v], mn + 1);
                    }
                }
            }
        }
        int ans = INF;
        for (int j = 0; j <= K; ++j) {
            ans = min(ans, *min_element(begin(dp[N - 1][j]), end(dp[N - 1][j])));
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}