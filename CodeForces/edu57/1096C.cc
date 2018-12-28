#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        constexpr double EPS = 1e-8;
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int ang = t;
            in >> ang;
            for (int n = 3; n <= 10'000; ++n) {
                double intang = 180 - 360. / n;
                double steps = intang / (n - 2);
                int num = ang / steps + 0.5;
                if (abs(ang / steps - num) < EPS && num <= n - 2 && num >= 1) {
                    out << n << "\n";
                    goto next_it;
                }
            }
            out << -1 << "\n";
            next_it:;
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
