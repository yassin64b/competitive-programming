#include <bits/stdc++.h>

using namespace std;

class kickstart_b_no_nine {
private:
    long long f(long long x) {
        string s(to_string(x));
        int n = s.size();
        vector<vector<long long>> dp1(n + 1, vector<long long>(9, 0));
        vector<vector<long long>> dp2(n + 1, vector<long long>(9, 0));
        dp1[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            int dig = s[i] - '0';
            for (int j = 0; j < 9; ++j) {
                if (dig < 9)
                    dp1[i + 1][(j + dig) % 9] += dp1[i][j];
            }
            for (int j = 0; j < 9; ++j) {
                for (int k = 0; k < dig && k < 9; ++k) {
                    dp2[i + 1][(j + k) % 9] += dp1[i][j];
                }
                for (int k = 0; k < 9; ++k) {
                    dp2[i + 1][(j + k) % 9] += dp2[i][j];
                }
            }
        }
        long long res = 0;
        for (int j = 1; j < 9; ++j) {
            res += dp1[n][j] + dp2[n][j];
        }
        return res - 1; // subtract 1 for zero
    }
    
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            long long F, L;
            in >> F >> L;
            out << "Case #" << t << ": " << f(L) - f(F - 1) << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    kickstart_b_no_nine solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
