/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, q, m;
        in >> n >> q >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<tuple<int, int, int>> query(q);
        for (int i = 0; i < q; ++i) {
            int t, l, r;
            in >> t >> l >> r;
            --l;
            --r;
            query[i] = {t, l, r};
        }
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            in >> b[i];
            --b[i];
        }
        // reverse problem: where did number that is after all queries at b[j] come from
        reverse(query.begin(), query.end());
        for (int j = 0; j < m; ++j) {
            int pos = b[j];
            for (int i = 0; i < q; ++i) {
                auto [t, l, r] = query[i];
                if (pos < l || pos > r) {
                    continue;
                }
                if (t == 1) {
                    if (pos == l) {
                        pos = r;
                    } else {
                        --pos;
                    }
                } else {
                    assert(t == 2);
                    int dist = pos - l;
                    pos = r - dist;
                }
            }
            out << a[pos] << " ";
        }
        out << "\n";
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
