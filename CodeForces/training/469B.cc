#include <bits/stdc++.h>

using namespace std;

class B469 {
public:
    void solve(istream& in, ostream& out) {
        int p, q, l, r;
        in >> p >> q >> l >> r;
        vector<int> a(p), b(p), c(q), d(q);
        for (int i = 0; i < p; ++i) {
            in >> a[i] >> b[i];
        }
        for (int i = 0; i < q; ++i) {
            in >> c[i] >> d[i];
        }
        int res = 0;
        for (int t = l; t <= r; ++t) {
            bool ok = false;
            for (int j = 0; !ok && j < q; ++j) {
                for (int i = 0; i < p; ++i) {
                    if (a[i] <= d[j] + t && c[j] + t <= b[i]) {
                        ok = true;
                        break;
                    }
                }
            }
            res += ok;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B469 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
