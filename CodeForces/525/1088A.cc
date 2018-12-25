#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int x;
        in >> x;
        if (x == 1) {
            out << "-1\n";
        } else {
            if (x % 2 == 0) {
                out << x << " " << 2 << "\n";
            } else {
                out << x - 1 << " " << 2 << "\n";
            }
        }
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
