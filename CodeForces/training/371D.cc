#include <bits/stdc++.h>

using namespace std;

class D371 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        set<int> active;
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            active.insert(i);
        }
        int m;
        in >> m;
        for (int i = 0; i < m; ++i) {
            int t;
            in >> t;
            if (t == 1) {
                int p, x;
                in >> p >> x;
                auto it = active.lower_bound(p - 1);
                while (it != end(active)) {
                    int add = min(a[*it], x);
                    a[*it] -= add;
                    res[*it] += add;
                    x -= add;
                    if (a[*it] == 0) {
                        it = active.erase(it);
                    } else {
                        break;
                    }
                }
            } else {
                int k;
                in >> k;
                out << res[k - 1] << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D371 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
