#include <bits/stdc++.h>

using namespace std;

class TaskF {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> c(k * n), f(n), h(k + 1);
        constexpr int MX = 100'001;
        vector<int> cnt_c(MX, 0), cnt_f(MX, 0);
        for (int i = 0; i < k * n; ++i) {
            in >> c[i];
            ++cnt_c[c[i]];
        }
        for (int i = 0; i < n; ++i) {
            in >> f[i];
            ++cnt_f[f[i]];
        }
        h[0] = 0;
        for (int i = 0; i < k; ++i) {
            in >> h[i + 1];
        }
        int res = 0;
        for (int i = 0; i < MX; ++i) {
            vector<vector<int>> dp(cnt_c[i] + 1, vector<int>(cnt_f[i] + 1, 0));
            for (int j = 1; j <= cnt_c[i]; ++j) {
                for (int b = 0; b <= k && b <= j; ++b) {
                    for (int a = 1; a <= cnt_f[i]; ++a) {
                        dp[j][a] = max(dp[j][a], dp[j - b][a - 1] + h[b]);
                    }
                }
            }
            res += dp[cnt_c[i]][cnt_f[i]];
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskF solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
