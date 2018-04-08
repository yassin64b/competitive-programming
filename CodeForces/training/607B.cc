#include <bits/stdc++.h>

using namespace std;

class B607 {
private:
    vector<vector<int>> dp;
    int calc(int i, int j, const vector<int> &c, int n) {
        if (i > j) {
            return 0;
        } else if (dp[i][j] != -1) {
            return dp[i][j];
        } else if (i == j) {
            return (dp[i][j] = 1);
        }
        dp[i][j] = calc(i + 1, j, c, n) + 1;
        for (int k = i + 2; k <= j; ++k) {
            if (c[i] == c[k]) {
                dp[i][j] = min(dp[i][j], calc(i + 1, k - 1, c, n) + calc(k + 1, j, c, n));
            }
        }
        if (c[i] == c[i + 1]) {
            dp[i][j] = min(dp[i][j], calc(i + 2, j, c, n) + 1);
        }
        return dp[i][j];
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            in >> c[i];
        }
        dp.assign(n, vector<int>(n, -1));
        out << calc(0, n - 1, c, n) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B607 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
