#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        if (n - k == 0 || n - k == n) {
            out << "0 0\n";
            return;
        }
        out << 1 << " " << min(n - k, k * 2) << "\n";
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
