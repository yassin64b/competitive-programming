#include <bits/stdc++.h>

using namespace std;

class gcj_brattleship {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int R, C, W;
            in >> R >> C >> W;
            int res = (C % W != 0) + W - 1;
            for (int i = 0; i < R; ++i) {
                for (int j = W - 1; j < C; j += W) {
                    ++res;
                }
            }
            assert(res <= R * C);
            out << "Case #" << t << ": " << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_brattleship solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
