#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int mn = 1'000'000'000;
        int N;
        in >> N;
        for (int a = 1; a <= N; ++a) {
            int b = (N + a - 1) / a;
            mn = min(mn, 2 * a + 2 * b);
        }
        out << mn << "\n";
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
