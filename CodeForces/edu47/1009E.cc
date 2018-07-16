#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        constexpr int MOD = 998244353;
        int n;
        in >> n;
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            in >> f[i];
        }
        int res = 0;
        int pow = 1, a = 1;
        for (int i = 1; i <= n; ++i) {
            res = (res + 1LL * a * f[n - i]) % MOD;
            a = 1LL * (i + 2) * pow % MOD;
            pow = (pow * 2) % MOD;
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
