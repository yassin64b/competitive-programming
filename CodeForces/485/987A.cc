#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> s(n), c(n);
        for (int i = 0; i < n; ++i) {
            in >> s[i];
        }
        vector<int> v(s);
        sort(begin(v), end(v));
        map<int, int> ind;
        int cur = 0;
        for (int x : v) {
            if (!ind.count(x)) {
                ind[x] = ++cur;
            }
        }
        for (int &x : s) {
            x = ind[x];
        }
        for (int i = 0; i < n; ++i) {
            in >> c[i];
        }
        constexpr long long INF = 1'000'000'000'000'000;
        vector<vector<long long>> dp(4, vector<long long>(n + 1, INF));
        dp[0][0] = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < 3; ++i) {
                for (int k = 0; k < s[j]; ++k) {
                    dp[i + 1][s[j]] = min(dp[i + 1][s[j]], dp[i][k] + c[j]);
                }
            }
        }
        long long res = *min_element(begin(dp[3]), end(dp[3]));
        out << (res == INF ? -1 : res) << "\n";
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
