#include <bits/stdc++.h>

using namespace std;

class gcj_steed_2_cruise_control {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int D, N;
            in >> D >> N;
            vector<int> K(N), S(N);
            double mx_reach_dest_t = 0;
            for (int i = 0; i < N; ++i) {
                in >> K[i] >> S[i];
                double reach_dest = (double)(D - K[i]) / S[i];
                mx_reach_dest_t = max(mx_reach_dest_t, reach_dest);
            }
            double mx_speed = D / mx_reach_dest_t;
            out.precision(7);
            out << fixed << "Case #" << t << ": " << mx_speed << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_steed_2_cruise_control solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
