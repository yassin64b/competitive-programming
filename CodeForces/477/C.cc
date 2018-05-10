#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, m, cl, ce, v;
        in >> n >> m >> cl >> ce >> v;
        vector<int> stairs(cl), elev(ce);
        for (int i = 0; i < cl; ++i) {
            in >> stairs[i];
        }
        for (int i = 0; i < ce; ++i) {
            in >> elev[i];
        }
        int q;
        in >> q;
        for (int i = 0; i < q; ++i) {
            int x1, y1, x2, y2;
            in >> x1 >> y1 >> x2 >> y2;
            int res = 1'000'000'000;
            
            if (x1 == x2) {
                res = abs(y2 - y1);
            }
            
            {
                auto s_it = upper_bound(begin(stairs), end(stairs), y1);
                if (s_it != end(stairs)) {
                    int loc = *s_it;
                    res = min(res, abs(loc - y1) + abs(x2 - x1) + abs(y2 - loc));
                }
                if (s_it != begin(stairs)) {
                    int loc = *--s_it;
                    res = min(res, abs(loc - y1) + abs(x2 - x1) + abs(y2 - loc));
                }
            }
            
            {
                auto e_it = upper_bound(begin(elev), end(elev), y1);
                if (e_it != end(elev)) {
                    int loc = *e_it;
                    res = min(res, abs(loc - y1) + (abs(x2 - x1) + v - 1) / v + abs(y2 - loc));
                }
                if (e_it != begin(elev)) {
                    int loc = *--e_it;
                    res = min(res, abs(loc - y1) + (abs(x2 - x1) + v - 1) / v + abs(y2 - loc));
                }
            }
            
            
            out << res << "\n";
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
