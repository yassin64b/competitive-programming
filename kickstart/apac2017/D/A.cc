#include <bits/stdc++.h>

using namespace std;

class apac_a {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, M;
            in >> N >> M;
            out.precision(17);
            out << fixed << "Case #" << t << ": " << 1. * (N - M) / (N + M) << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    apac_a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
