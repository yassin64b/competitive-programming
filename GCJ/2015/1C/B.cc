#include <bits/stdc++.h>

using namespace std;

class gcj_typewriter_monkey {
private:
    double solve_small(int K, int L, int S, string keyboard, string target) {
        string cur;
        int mx_ban_needed = 0, num_generations = 0;
        int num_ban_needed = brute(K, L, S, keyboard, target, cur, mx_ban_needed, num_generations);
        return mx_ban_needed - 1. * num_ban_needed / num_generations;
    }
    int brute(int K, int L, int S, const string &k, const string &t, string &cur, int &mx, int &num) {
        if ((int)cur.size() == S) {
            int res = 0;
            for (int i = 0; i + L <= S; ++i) {
                res += (cur.substr(i, L) == t);
            }
            ++num;
            mx = max(mx, res);
            return res;
        }
        int res = 0;
        for (int i = 0; i < K; ++i) {
            cur += k[i];
            res += brute(K, L, S, k, t, cur, mx, num);
            cur.pop_back();
        }
        return res;
    }
    double solve_large(int K, int L, int S, string keyboard, string target) {
        for (char c : target) {
            if (count(begin(keyboard), end(keyboard), c) == 0) {
                return 0.;
            }
        }
        vector<vector<double>> dp(S + 1, vector<double>(L + 1, 0.));
        for (int i = 0; i <= S; ++i) dp[i][0] = 1.;
        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < L; ++j) {
                for (char c : keyboard) {
                    if (c == target[j]) {
                        dp[i + 1][j + 1] += 1. / K * dp[i][j];
                    }
                }
            }
        }
        double exp_num_ban_needed = 0.;
        for (int i = 0; i <= S; ++i) {
            exp_num_ban_needed += dp[i][L];
        }
        int mx_ban_needed = 1;
        string cur = target;
        for (int i = 1; i + L <= S; ++i) {
            bool match = true;
            for (int j = i; j < (int)cur.size(); ++j) {
                if (cur[j] != target[j - i]) match = false;
            }
            if (match) {
                ++mx_ban_needed;
                cur += target.substr((int)cur.size() - i);
            }
        }
        return mx_ban_needed - exp_num_ban_needed;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int K, L, S;
            in >> K >> L >> S;
            string keyboard, target;
            in >> keyboard >> target;
            out.precision(17);
            out << "Case #" << t << ": " << fixed << solve_large(K, L, S, keyboard, target) << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_typewriter_monkey solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
