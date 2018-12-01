#include <bits/stdc++.h>

using namespace std;

class D540 {
public:
    void solve(istream& in, ostream& out) {
        int r, s, p;
        in >> r >> s >> p;
        vector<vector<vector<double>>> dp(r + 1, vector<vector<double>>(s + 1,
                                                                        vector<double>(p + 1, 0.)));
        dp[r][s][p] = 1.;
        for (int i = r; i >= 0; --i) {
            for (int j = s; j >= 0; --j) {
                for (int k = p; k >= 0; --k) {
                    int num = i + j + k;
                    if ((i > 0) + (j > 0) + (k > 0) < 2) { // end state
                        continue;
                    }
                    double rs = i * j, rp = i * k, sp = j * k;
                    double sum = rs + rp + sp;
                    if (j > 0) dp[i][j - 1][k] += rs / sum * dp[i][j][k];
                    if (i > 0) dp[i - 1][j][k] += rp / sum * dp[i][j][k];
                    if (k > 0) dp[i][j][k - 1] += sp / sum * dp[i][j][k];
                }
            }
        }
        double pr = 0, ps = 0, pp = 0;
        for (int i = 1; i <= r; ++i) pr += dp[i][0][0];
        for (int j = 1; j <= s; ++j) ps += dp[0][j][0];
        for (int k = 1; k <= p; ++k) pp += dp[0][0][k];
        out.precision(10);
        out << fixed << pr << " " << ps << " " << pp << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D540 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
