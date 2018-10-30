#include <bits/stdc++.h>

using namespace std;

class E479 {
public:
    void solve(istream& in, ostream& out) {
        constexpr int MOD = 1'000'000'007;
        int n, a, b, k;
        in >> n >> a >> b >> k;
        vector<int> dp(n + 1, 0);
        dp[a] = 1;
        for (int it = 0; it < k; ++it) {
            vector<int> nxt(n + 2, 0), add(n + 1, 0);
            for (int i = 1, l = 1, r = 1; i <= n; ++i) {
                if (i == b) {
                    continue;
                }
                r = max(r, i);
                while (abs(i - l) >= abs(i - b)) ++l;
                while (r <= n && abs(i - r) < abs(i - b)) ++r;
                
                nxt[l] = (nxt[l] + dp[i]) % MOD;
                nxt[r] = (nxt[r] - dp[i]) % MOD;
                add[i] = (add[i] - dp[i]) % MOD;
            }
            for (int i = 1; i <= n; ++i) {
                nxt[i] = ((nxt[i] + nxt[i - 1]) % MOD + MOD) % MOD;
            }
            for (int i = 1; i <= n; ++i) {
                nxt[i] = ((nxt[i] + add[i]) % MOD + MOD) % MOD;
                dp[i] = nxt[i];
            }
        }
        out << accumulate(begin(dp), end(dp), 0LL) % MOD << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    E479 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
