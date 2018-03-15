#include <bits/stdc++.h>

using namespace std;

class apac_a {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, M;
            in >> N >> M;
            vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
            dp[0][0] = 1;
            for (int i = 1; i <= N; ++i) {
                for (int j = 0; j < i && j <= M; ++j) {
                    dp[i][j] += dp[i - 1][j];
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
            long long all = 1;
            for (int i = M+N; i >= 1; --i) {
                all *= i;
            }
            long long nfac = 1, mfac = 1;
            for (int i = N; i >= 1; --i) nfac *= i;
            for (int i = M; i >= 1; --i) mfac *= i;
            all /= nfac;
            all /= mfac;
            out.precision(17);
            out << "Case #" << t << ": " << fixed << 1. * dp[N][M] / all << endl;
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    apac_a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
