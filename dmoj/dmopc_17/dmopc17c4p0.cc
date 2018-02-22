#include <bits/stdc++.h>

using namespace std;

class dmopc17c4p1 {
public:
    void solve(istream& in, ostream& out) {
        int x1, x2, x3, y1, y2, y3;
        in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int res = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        res = min(res, (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        res = min(res, (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmopc17c4p1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
