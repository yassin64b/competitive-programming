#include <bits/stdc++.h>

using namespace std;

class B570 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        if (n == 1) {
            out << 1 << "\n";
            return;
        }
        int left = m - 1, right = n - m;
        if (left >= right) {
            out << m - 1 << "\n";
        } else {
            out << m + 1 << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B570 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
