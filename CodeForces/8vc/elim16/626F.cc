#include <bits/stdc++.h>

using namespace std;

class TaskF {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        sort(begin(a), end(a));
        constexpr int MOD = 1'000'000'007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> nxt(n + 1, vector<int>(k + 1, 0));
            for (int j = 0; j <= n; ++j) {
                for (int x = 0; x <= k; ++x) {
                    int nx = j * (a[i] - (i > 0 ? a[i - 1] : 0));
                    if (nx + x > k) continue;
                    // open a new group and close immediately
                    nxt[j][nx + x] = (nxt[j][nx + x] + dp[j][x]) % MOD;
                    // add to one of j currently open groups
                    if (j > 0) nxt[j][nx + x] = (nxt[j][nx + x] + 1LL * j * dp[j][x]) % MOD;
                    // open a new group
                    if (j < n) nxt[j + 1][nx + x] = (nxt[j + 1][nx + x] + dp[j][x]) % MOD;
                    // add to one of j open groups and close that one
                    if (j > 0) nxt[j - 1][nx + x] = (nxt[j - 1][nx + x] + 1LL * j * dp[j][x]) % MOD;
                }
            }
            dp = nxt;
        }
        int res = 0;
        for (int x = 0; x <= k; ++x) {
            res = (res + dp[0][x]) % MOD;
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
