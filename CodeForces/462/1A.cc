#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int res = 0, cur1 = 0;
        vector<int> suf2(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suf2[i] = suf2[i + 1] + (a[i] == 2);
        }
        for (int i = 0; i < n; ++i) {
            vector<pair<int, int>> dp(n);
            dp[i] = {(a[i] == 2), (a[i] == 1)};
            for (int j = i + 1; j < n; ++j) {
                dp[j].first = dp[j - 1].first + (a[j] == 2);
                dp[j].second = max(dp[j - 1].first, dp[j - 1].second) + (a[j] == 1);
            }
            for (int j = i; j < n; ++j) {
                res = max(res, cur1 + max(dp[j].first, dp[j].second) + suf2[j + 1]);
            }
            cur1 += (a[i] == 1);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
