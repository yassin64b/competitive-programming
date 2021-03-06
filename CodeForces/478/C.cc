#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, q;
        in >> n >> q;
        vector<i64> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<i64> k(q);
        for (int i = 0; i < q; ++i) {
            in >> k[i];
        }
        
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        
        i64 cur = 0;
        for (int t = 0; t < q; ++t) {
            cur += k[t];
            if (cur >= a.back()) {
                cur = 0;
                out << n << "\n";
            } else {
                auto it = upper_bound(begin(a), end(a), cur);
                out << end(a) - it << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
