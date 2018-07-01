#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        constexpr int MOD = 998244353;
        vector<vector<int>> ncr(1'000 + 1, vector<int>(1'000 + 1));
        for(int i = 0; i <= 1'000; i++) {
            ncr[i][0] = 1;
        }
        for(int i = 1; i <= 1'000; i++) {
            for(int j = 1; j <= 1'000; j++) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
            }
        }
        vector<int> dp(n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            for (int j = i + a[i]; a[i] > 0 && j < n; ++j) {
                dp[i] = (dp[i] + 1LL * ncr[j - i - 1][a[i] - 1] * (dp[j + 1] + 1)) % MOD;
            }
        }
        out << dp[0] << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
