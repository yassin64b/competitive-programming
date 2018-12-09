#include <bits/stdc++.h>

using namespace std;

class D148 {
public:
    void solve(istream& in, ostream& out) {
        int w, b;
        in >> w >> b;
        vector<vector<pair<double, double>>> dp(w + 1, vector<pair<double, double>>(b + 1, {0., 0.}));
        dp[w][b].first = 1;
        double res = 0.;
        for (int i = w; i >= 0; --i) {
            for (int j = b; j >= 0; --j) {
                int sum = i + j;
                if (sum == 0) continue;
                
                double pw = dp[i][j].first * i / sum; // princess draws w
                double pb = dp[i][j].first * j / sum; // princess draws b
                res += pw;
                if (j > 0) dp[i][j - 1].second += pb;
                
                double dw = dp[i][j].second * i / sum; // dragon draws w;
                double db = dp[i][j].second * j / sum; // dragon draws b;
                if (sum == 1) {
                    if (j > 0) dp[i][j - 1].first += db;
                } else {
                    double dbw = db * i / (sum - 1); // w jumps out
                    double dbb = db * (j - 1) / (sum - 1); // b jumps out;
                    if (i > 0 && j > 0) dp[i - 1][j - 1].first += dbw;
                    if (j > 1) dp[i][j - 2].first += dbb;
                }
            }
        }
        out.precision(17);
        out << fixed << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D148 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
