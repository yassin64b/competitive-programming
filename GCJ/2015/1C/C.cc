#include <bits/stdc++.h>

using namespace std;

class gcj_less_money_more_problems {
private:
    int solve_small(const vector<int> &coins, int C, int D, int V) {
        vector<bool> dp(V + 1, 0);
        dp[0] = 1;
        for (int k = 0; k < D; ++k) {
            for (int i = V; i >= 0; --i) {
                if (dp[i]) {
                    for (int c = 1; c <= C; ++c)
                        if (i + 1LL * c * coins[k] <= V)
                            dp[i + c * coins[k]] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= V; ++i) {
            if (dp[i] == 0) {
                ++ans;
                for (int j = V; j >= 0; --j) {
                    if (dp[j]) {
                        for (int c = 1; c <= C; ++c)
                            if (j + 1LL * c * i <= V)
                                dp[j + c * i] = 1;
                    }
                }
            }
        }
        return ans;
    }
    int solve_large(const vector<int> &coins, int C, int D, int V) {
        long long sum = 0;
        int ind = 0, ans = 0;
        while (sum < V) {
            long long add = sum + 1;
            if (ind < D && coins[ind] <= add) {
                add = coins[ind];
                ++ind;
            } else {
                ++ans;
            }
            sum += add * C;
        }
        return ans;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int C, D, V;
            in >> C >> D >> V;
            vector<int> coins(D);
            for (int i = 0; i < D; ++i) {
                in >> coins[i];
            }
            
            out << "Case #" << t << ": " << solve_large(coins, C, D, V) << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_less_money_more_problems solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
