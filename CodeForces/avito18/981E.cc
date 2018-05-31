#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n, q;
        in >> n >> q;
        vector<int> dp(n + 1, 0);
        vector<tuple<int, int, int>> v(q);
        for (int i = 0; i < q; ++i) {
            int l, r, x;
            in >> l >> r >> x;
            v[i] = {l, r, x};
        }
        dp[0] = n;
        sort(begin(v), end(v));
        for (auto [l, r, x] : v) {
            for (int i = n - x; i >= 0; --i) {
                if (dp[i] >= l) {
                    dp[i + x] = max(dp[i + x], min(r, dp[i]));
                }
            }
        }
        vector<int> res;
        for (int i = 1; i <= n; ++i) {
            if (dp[i]) {
                res.push_back(i);
            }
        }
        out << res.size() << "\n";
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
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
