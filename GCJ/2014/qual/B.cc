#include <bits/stdc++.h>

using namespace std;

class gcj_cookie_clicker_alpha {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            double C, F, X;
            in >> C >> F >> X;
            double cur_t = 0., cur_f = 2., best_t = 1e18;
            while (true) {
                double fin_t = X / cur_f;
                if (cur_t + fin_t > best_t) {
                    break;
                }
                best_t = cur_t + fin_t;
                double next_c_t = C / cur_f;
                cur_t += next_c_t;
                cur_f += F;
            }
            out.precision(7);
            out << fixed << "Case #" << t << ": " << best_t << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_cookie_clicker_alpha solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
