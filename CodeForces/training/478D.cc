#include <bits/stdc++.h>

using namespace std;

class D478 {
public:
    void solve(istream& in, ostream& out) {
        int r, g;
        in >> r >> g;
        int low = 1, high = 1'000, h = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool ok = true;
            for (int cur = mid, cr = r, cg = g; cur >= 1; --cur) {
                if (cr > cg) {
                    cr -= cur;
                } else {
                    cg -= cur;
                }
                if (cr < 0 || cg < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                low = mid + 1;
                h = mid;
            } else {
                high = mid - 1;
            }
        }
        constexpr int MOD = 1'000'000'007;
        // dp[j] = num of ways to have j red blocks left
        // green blocks left can be calculated from j and the level (i)
        vector<int> dp(r + 1, 0);
        dp[r] = 1;
        for (int i = h, sum = 0; i >= 1; --i) {
            for (int j = 0; j <= r; ++j) {
                int k = g - (sum - (r - j));
                if (j >= i) dp[j - i] = (dp[j - i] + dp[j]) % MOD;
                if (!(k >= i)) dp[j] = 0;
            }
            sum += i;
        }
        int res = 0;
        for (int j = 0; j <= r; ++j) {
            res = (res + dp[j]) % MOD;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D478 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
