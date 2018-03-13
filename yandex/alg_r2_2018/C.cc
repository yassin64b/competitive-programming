#include <bits/stdc++.h>

using namespace std;

class yndx_c {
public:
    void solve(istream& in, ostream& out) {
        int n, m, ds, cs, da, ca;
        in >> n >> m >> ds >> cs >> da >> ca;
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            in >> h[i];
        }
        
        sort(begin(h), end(h));
        int res = 0;
        for (int num_a = 0; num_a <= 100; ++num_a) {
            int cur_m = m - num_a * ca, cur_res = 0;
            for (int i = 0; i < n; ++i) {
                int num_s = (max(0, h[i] - num_a * da) + ds - 1) / ds;
                cur_m -= num_s * cs;
                if (cur_m >= 0) {
                    ++cur_res;
                }
            }
            res = max(res, cur_res);
        }
        out << res << "\n";
        
        /*vector<vector<int>> dp(n + 1, vector<int>(100 + 1, -1)); // works also
        dp[0][0] = m;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k <= 100; ++k) {
                for (int j = 0; j + k <= 100; ++j) {
                    int left_h = h[i] - (k + j) * da;
                    int num = (max(0, left_h) + ds - 1) / ds;
                    dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][k] - j * ca - num * cs);
                }
            }
        }
        for (int i = n; i >= 0; --i) {
            for (int j = 0; j <= 100; ++j) {
                if (dp[i][j] >= 0) {
                    assert(res == i);
                    out << i << "\n";
                    return;
                }
            }
        }
        assert(false);*/
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    yndx_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
