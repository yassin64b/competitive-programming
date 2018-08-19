#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int n;
            in >> n;
            vector<int> a(n);
            map<int, int> m;
            for (int i = 0; i < n; ++i) {
                in >> a[i];
                ++m[a[i]];
            }
            double val = 1e18;
            int x = -1, y = -1;
            for (auto [u, v] : m) {
                if (v >= 4) {
                    val = 16;
                    x = y = u;
                }
            }
            auto it1 = begin(m), it2 = begin(m);
            for (int i = 0, j = 0; ;) {
                while (it1 != end(m) && it1->second < 2) {
                    ++it1;
                    ++i;
                }
                if (it1 == end(m)) break;
                while (j <= i) {
                    ++it2;
                    ++j;
                }
                while (it2 != end(m) && it2->second < 2) {
                    ++it2;
                    ++j;
                }
                if (it2 == end(m)) break;
                int cx = it1->first, cy = it2->first;
                double cur = (2. * cx + 2. * cy) * (2. * cx + 2. * cy) / (1. * cx * cy);
                if (cur < val) {
                    val = cur;
                    x = cx;
                    y = cy;
                }
                ++it1;
                ++i;
            }
            out << x << " " << x << " " << y << " " << y << "\n";
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
