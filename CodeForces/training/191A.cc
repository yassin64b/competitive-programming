#include <bits/stdc++.h>

using namespace std;

class A191 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<string> names(n);
        for (int i = 0; i < n; ++i) {
            in >> names[i];
        }
        vector<vector<int>> dp(26, vector<int>(26, -1)); // i start letter, j current last letter
        for (int k = 0; k < n; ++k) {
            int j = names[k][0] - 'a';
            int nj = names[k].back() - 'a';
            int len = names[k].size();
            for (int i = 0; i < 26; ++i) {
                if (dp[i][j] != -1) {
                    dp[i][nj] = max(dp[i][nj], dp[i][j] + len);
                }
            }
            dp[j][nj] = max(dp[j][nj], len); // start new dynasty
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res = max(res, dp[i][i]);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A191 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
