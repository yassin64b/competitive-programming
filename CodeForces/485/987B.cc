#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int x, y;
        in >> x >> y;
        double a = y * log(x);
        double b = x * log(y);
        if (abs(b - a) < 1e-6) {
            out << "=\n";
        } else if (a > b) {
            out << ">\n";
        } else {
            out << "<\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
