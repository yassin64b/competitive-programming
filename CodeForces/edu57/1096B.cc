#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        constexpr int MOD = 998244353;
        int n;
        in >> n;
        string s;
        in >> s;
        int res = 0;
        int pre_cnt = 0, suf_cnt = 0;
        for (int i = 0; i < n && s[i] == s[0]; ++i, ++pre_cnt);
        for (int i = n - 1; i >= 0 && s[i] == s[n - 1]; --i, ++suf_cnt);
        if (s[0] == s[n - 1]) {
            res = (1LL * (pre_cnt + 1) * (suf_cnt + 1)) % MOD;
        } else {
            res = pre_cnt + 1 + suf_cnt;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
