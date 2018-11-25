#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskC {
private:
    pair<i64, i64> num_white(i64 x1, i64 y1, i64 x2, i64 y2) {
        i64 n = y2 - y1 + 1, m = x2 - x1 + 1;
        if (x1 % 2 == y1 % 2) { // lower left cell white
            if (x2 % 2 == y2 % 2) { // upper right cell white
                return {(n * m + 1) / 2, n * m - (n * m + 1) / 2};
            } else { // upper right black
                return {(n * m) / 2, n * m - (n * m) / 2};
            }
        } else { // lower left cell black
            if (x2 % 2 == y2 % 2) {  // upper right cell white
                return {(n * m) / 2, n * m - (n * m) / 2};
            } else { // upper right black
                return {n * m - (n * m + 1) / 2, (n * m + 1) / 2};
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            i64 n, m;
            in >> n >> m;
            i64 x1, y1, x2, y2;
            in >> x1 >> y1 >> x2 >> y2;
            i64 x3, y3, x4, y4;
            in >> x3 >> y3 >> x4 >> y4;
            auto [w, b] = num_white(1, 1, m, n);
            auto [w1, b1] = num_white(x1, y1, x2, y2);
            auto [w2, b2] = num_white(x3, y3, x4, y4);
            i64 ox1 = max(x1, x3), oy1 = max(y1, y3);
            i64 ox2 = min(x2, x4), oy2 = min(y2, y4);
            auto [ow, ob] = num_white(ox1, oy1, ox2, oy2);
            if (ox1 <= ox2 && oy1 <= oy2) {
                w = w - w1 + (x2 - x1 + 1) * (y2 - y1 + 1);
                i64 overlap = (ox2 - ox1 + 1) * (oy2 - oy1 + 1);
                w = w - overlap;
                w = w - (w2 - ow);
                b = n * m - w;
                out << w << " " << b << "\n";
            } else {
                w = w - w1 + (x2 - x1 + 1) * (y2 - y1 + 1);
                w = w - w2;
                b = n * m - w;
                out << w << " " << b << "\n";
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
