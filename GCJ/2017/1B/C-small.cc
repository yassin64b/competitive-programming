#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, Q;
        cin >> N >> Q;
        vector<int> E(N), S(N);
        for (int i = 0; i < N; ++i) {
            cin >> E[i] >> S[i];
        }
        vector<vector<int>> D(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> D[i][j];
            }
        }

        vector<double> dp(N, 1e18);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            int cur_e = E[i];
            double time = 0;
            for (int j = i+1; cur_e >= 0 && j < N; ++j) {
                cur_e -= D[j-1][j];
                time += D[j-1][j] / (double)S[i];
                if (cur_e >= 0) {
                    dp[j] = min(dp[j], time + dp[i]);
                }
            }
        }

        cout << "Case #" << t << ": ";
        for (int q = 0; q < Q; ++q) {
            int U, V;
            cin >> U >> V;
            --U; --V;
            cout.precision(17);
            cout << fixed << dp[V] << (q == Q-1 ? "\n" : " ");
        }
    }
}