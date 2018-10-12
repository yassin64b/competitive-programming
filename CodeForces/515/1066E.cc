#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 998244353;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        string a, b;
        in >> a >> b;
        if (n < m) {
            a = string(m - n, '0') + a;
        } else if (m < n) {
            b = string(n - m, '0') + b;
        }
        n = m = max(n, m);
        vector<int> cnt(n, 0);
        for (int i = 0, cur = 0; i < n; ++i) {
            cur += (b[i] == '1');
            cnt[i] = cur;
        }
        int res = 0;
        for (int i = n - 1, mul = 1; i >= 0; --i) {
            if (a[i] == '1') {
                res = (res + 1LL * mul * cnt[i]) % MOD;
            }
            mul = (mul * 2) % MOD;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
