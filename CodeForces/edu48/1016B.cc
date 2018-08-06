#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, m, q;
        in >> n >> m >> q;
        string s, t;
        in >> s >> t;
        vector<int> cnt(n, 0);
        for (int i = 0; i + m <= n; ++i) {
            cnt[i] = (t == s.substr(i, m));
        }
        for (int i = 1; i < n; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 0, l, r; i < q; ++i) {
            in >> l >> r;
            if (r - l + 1 < m) {
                out << 0 << "\n";
            } else if (l == 1) {
                out << cnt[r - m] << "\n";
            } else {
                out << cnt[r - m] - cnt[l - 2] << "\n";
            }
        }
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
