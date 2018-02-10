#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, k, t;
        in >> n >> k >> t;
        if (t <= k) {
            out << t << "\n";
        } else if (t <= n) {
            out << k << "\n";
        } else {
            out << (n + k) - t << "\n";
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
