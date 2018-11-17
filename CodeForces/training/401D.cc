#include <bits/stdc++.h>

using namespace std;

class D401 {
public:
    void solve(istream& in, ostream& out) {
        string n;
        int m;
        in >> n >> m;
        int len = n.size();
        vector<vector<long long>> dp(1 << len, vector<long long>(m, 0));
        dp[0][0] = 1;
        for (int mask = 0; mask < (1 << len); ++mask) {
            for (int rem = 0; rem < m; ++rem) {
                if (dp[mask][rem] == 0) continue;
                for (int i = 0; i < len; ++i) {
                    if (!(mask == 0 && n[i] == '0') && (mask & (1 << i)) == 0) {
                        dp[mask | (1 << i)][(10 * rem + n[i] - '0') % m] += dp[mask][rem];
                    }
                }
            }
        }
        long long ans = dp[(1 << len) - 1][0];
        for (char c = '0'; c <= '9'; ++c) {
            for (int i = 2; i <= count(begin(n), end(n), c); ++i) {
                ans /= i;
            }
        }
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D401 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
