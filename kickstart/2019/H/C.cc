#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        vector<int> A(10), B;
        for (int i = 1; i < 10; ++i) {
            cin >> A[i];
            if (A[i] > 20) {
                for (int j = 0; j < 20 + (A[i] % 2); ++j) {
                    B.push_back(i);
                }
            } else {
                for (int j = 0; j < A[i]; ++j) {
                    B.push_back(i);
                }
            }
        }
        int cnt = B.size();
        int num_pos = (cnt + 1) / 2;
        vector<vector<int>> dp(cnt + 1, vector<int>(11, 0));
        dp[0][0] = 1;
        for (int c = 0; c < cnt; ++c) {
            vector<vector<int>> nxt(cnt + 1, vector<int>(11, 0));
            for (int i = 0; i <= cnt; ++i) {
                for (int j = 0; j < 11; ++j) {
                    if (dp[i][j] && i + 1 <= cnt) {
                        int nj = (j + B[c]) % 11;
                        nxt[i + 1][nj] = 1;
                    }
                    if (dp[i][j]) {
                        int nj = (j - B[c] + 11) % 11;
                        nxt[i][nj] = 1;
                    }
                }
            }
            dp = nxt;
        }
        bool ok = (dp[num_pos][0] == 1);
        cout << "Case #" << t << ": " << (ok ? "YES" : "NO") << "\n";
    }


    return 0;
}