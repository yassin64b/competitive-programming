#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        constexpr int MOD = 998244353;
        int n, m, k;
        in >> n >> m >> k;
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        dp[0][0] = m;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j]; // color the same
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - 1] * (m - 1)) % MOD;
                }
            }
        }
        out << dp[n - 1][k] << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
