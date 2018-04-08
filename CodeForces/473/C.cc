#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        // first tree
        if (n <= 5) {
            out << -1 << "\n";
        } else {
            out << "1 2\n1 3\n1 4\n4 5\n4 6\n";
            for (int i = 7; i <= n; ++i) {
                out << "4 " << i << "\n";
            }
        }
        // second tree
        for (int i = 2; i <= n; ++i) {
            out << "1 " << i << "\n";
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
