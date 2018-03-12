#include <bits/stdc++.h>

using namespace std;

class arc091_a {
public:
    void solve(istream& in, ostream& out) {
        int N, M;
        in >> N >> M;
        if (N == 1 || M == 1) {
            if (N == 1 && M == 1) {
                out << 1 << "\n";
            } else if (N == 1) {
                out << M - 2 << "\n";
            } else {
                out << N - 2 << "\n";
            }
        } else {
            long long res = 1LL * (N - 2) * (M - 2);
            out << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc091_a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
