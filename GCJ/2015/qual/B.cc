#include <bits/stdc++.h>

using namespace std;

class gcd_infinite_house_of_pancakes {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int D;
            in >> D;
            vector<int> p(D);
            int mx_p = 0;
            for (int i = 0; i < D; ++i) {
                in >> p[i];
                mx_p = max(mx_p, p[i]);
            }
            int res_time = mx_p + 1;
            for (int j = 1; j <= mx_p; ++j) {
                int cur_t = 0;
                for (int i = 0; i < D; ++i) {
                    int num = (p[i] + j - 1) / j;
                    cur_t += num - 1;
                }
                res_time = min(res_time, cur_t + j);
            }
            assert(res_time <= 1000);
            out << "Case #" << t << ": " << res_time << "\n";
            out.flush();
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcd_infinite_house_of_pancakes solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
