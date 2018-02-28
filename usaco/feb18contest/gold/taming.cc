#include <bits/stdc++.h>

using namespace std;

class taming {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            in >> a[i];
        }
        constexpr int INF = 1000000;
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, INF)));
        // min cost i+1 breakouts, last breakout at j, cost up to index k
        dp[0][0][0] = (a[0] != 0);
        for (int k = 1; k < N; ++k) {
            dp[0][0][k] = dp[0][0][k - 1] + (a[k] != k);
        }
        for (int i = 1; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                for (int lj = 0; lj < j; ++lj) {
                    int tmp = dp[i - 1][lj][j - 1] + (a[j] != 0);
                    dp[i][j][j] = min(dp[i][j][j], tmp);
                }
                for (int k = j + 1; k < N; ++k) {
                    int tmp = dp[i][j][k - 1] + (a[k] != k - j);
                    dp[i][j][k] = min(dp[i][j][k], tmp);
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            int res = INF;
            for (int j = 0; j < N; ++j) {
                res = min(res, dp[i][j][N - 1]);
            }
            out << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    taming solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
