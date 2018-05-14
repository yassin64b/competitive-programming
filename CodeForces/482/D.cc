#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            in >> b[i];
        }
        if (n <= 2) {
            out << 0 << "\n";
            return;
        }
        int res = 100'001;
        for (int a1 = -1; a1 <= 1; ++a1) {
            for (int a2 = -1; a2 <= 1; ++a2) {
                vector<int> c(b);
                c[0] += a1;
                c[1] += a2;
                int cur = (a1 != 0) + (a2 != 0);
                const int diff = c[1] - c[0];
                bool ok = true;
                for (int i = 2; i < n; ++i) {
                    int need = c[i - 1] + diff;
                    if (abs(need - c[i]) > 1) {
                        ok = false;
                    } else if (need != c[i]) {
                        ++cur;
                        c[i] = need;
                    }
                }
                if (ok) {
                    res = min(res, cur);
                }
            }
        }
        out << (res > 100'000 ? -1 : res) << "\n";
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
