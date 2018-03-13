#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        long long a, b;
        in >> a >> b;
        while (a && b && (a >= 2 * b || b >= 2 * a)) {
            if (a >= 2 * b) {
                long long div = a / (2 * b);
                a -= 2 * b * div;
            } else {
                long long div = b / (2 * a);
                b -= 2 * a * div;
            }
        }
        out << a << " " << b << "\n";
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
