#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int x, y, z, t1, t2, t3;
        in >> x >> y >> z >> t1 >> t2 >> t3;
        int elev = 3 * t3 + (abs(z - x) + abs(x - y)) * t2;
        int stairs = abs(x - y) * t1;
        out << (stairs < elev ? "NO" : "YES") << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
