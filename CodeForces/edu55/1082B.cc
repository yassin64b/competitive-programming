#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        int cnt_g = count(begin(s), end(s), 'G');
        vector<pair<int, int>> dp(n + 1);
        dp[0] = {0, 0};
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'G') {
                dp[i + 1].first = dp[i].first + 1;
                dp[i + 1].second = dp[i].second + 1;
            } else {
                dp[i + 1].first = 0;
                dp[i + 1].second = dp[i].first + 1;
            }
            ans = max(ans, max(dp[i + 1].first, dp[i + 1].second));
        }
        ans = min(ans, cnt_g);
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
