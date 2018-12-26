#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n, c;
        in >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        // search for best l,r s.t.:
        // (cnt_c in prefix + max occ. in [l,r] + cnt_c in suffix) is maximal
        vector<int> suf_cnt_c(n + 1, 0);
        suf_cnt_c[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            suf_cnt_c[i] = (a[i] == c) + suf_cnt_c[i + 1];
        }
        constexpr int MXV = 500'000;
        vector<int> dp(MXV + 1, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            // extend current [l,r] part or start new [l,r] part
            dp[a[i]] = max(dp[a[i]] + 1, dp[c] + 1);
            res = max(res, dp[a[i]] + suf_cnt_c[i + 1]);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
