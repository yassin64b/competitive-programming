#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<i64> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        i64 mask = 0;
        for (int shift = 60; shift >= 0; --shift) {
            mask |= (1LL << shift);
            
            vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
            dp[0][0] = 1;
            for (int i = 0; i < n; ++i) {
                i64 cur = 0;
                for (int j = i; j < n; ++j) {
                    cur += a[j];
                    if ((cur & mask) == mask) {
                        for (int l = 0; l < k; ++l) {
                            if (dp[i][l]) {
                                dp[j + 1][l + 1] = 1;
                            }
                        }
                    }
                }
            }
            
            if (!dp[n][k]) {
                mask &= ~(1LL << shift);
            }
        }
        out << mask << "\n";
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
