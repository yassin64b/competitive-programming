#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        for (int x1 = 1; x1 <= n; ++x1) {
            if (n % x1 == 0) {
                int x2 = n / x1;
                if (x2 < k) {
                    int x = x1 * k + x2;
                    out << x << "\n";
                    return;
                }
            }
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
