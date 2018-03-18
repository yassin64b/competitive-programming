#include <bits/stdc++.h>

using namespace std;

class gcj_counter_culture {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<int> dp(N + 1, 1'000'001);
            dp[1] = 1;
            for (int i = 1; i < N; ++i) {
                string s(to_string(i));
                dp[i + 1] = min(dp[i + 1], dp[i] + 1);
                reverse(begin(s), end(s));
                int x = stoi(s);
                if (x <= N && x > i) {
                    dp[x] = min(dp[x], dp[i] + 1);
                }
            }
            out << "Case #" << t << ": " << dp[N] << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_counter_culture solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
