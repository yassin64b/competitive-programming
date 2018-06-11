#include <bits/stdc++.h>

using namespace std;

class TaskF {
public:
    void solve(istream& in, ostream& out) {
        int a, n, m;
        in >> a >> n >> m;
        vector<pair<int, int>> lr(n), xp(m);
        vector<int> rain(2'001, 0);
        for (int i = 0; i < n; ++i) {
            in >> lr[i].first >> lr[i].second;
            for (int j = lr[i].first + 1; j <= lr[i].second; ++j) {
                rain[j] = 1;
            }
        }
        vector<int> umb(2'001, 0);
        for (int i = 0; i < m; ++i) {
            in >> xp[i].first >> xp[i].second;
            if (!umb[xp[i].first]) {
                umb[xp[i].first] = xp[i].second;
            }
            umb[xp[i].first] = min(umb[xp[i].first], xp[i].second);
        }
        sort(begin(lr), end(lr));
        sort(begin(xp), end(xp));
        if (xp[0].first > lr[0].first) {
            out << -1 << "\n";
            return;
        }
        constexpr int INF = 1'000'000'000;
        vector<int> dp(2'001, INF);
        for (int i = 0; i <= lr[0].first; ++i) {
            dp[i] = 0;
        }
        for (int i = 0; i <= 2000; ++i) {
            if (umb[i]) {
                for (int j = i + 1, cur = umb[i]; j <= 2000; ++j, cur += umb[i]) {
                    dp[j] = min(dp[j], cur + dp[i]);
                }
                for (int j = 1; j <= 2000; ++j) {
                    if (!rain[j]) {
                        dp[j] = min(dp[j], dp[j - 1]);
                    }
                }
            }
        }
        out << dp[a] << "\n";
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
