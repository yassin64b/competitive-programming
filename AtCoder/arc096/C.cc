#include <bits/stdc++.h>

using namespace std;

class arc096_c {
public:
    void solve(istream& in, ostream& out) {
        int A, B, C, X, Y;
        in >> A >> B >> C >> X >> Y;
        int cost = 1'000'000'000;
        for (int c = 0; c <= 2 * max(X, Y); ++c) {
            int a = max(0, X - c / 2);
            int b = max(0, Y - c / 2);
            cost = min(cost, a * A + b * B + c * C);
        }
        out << cost << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc096_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
