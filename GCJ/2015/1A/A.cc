#include <bits/stdc++.h>

using namespace std;

class gcj_mushroom_monster {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<int> m(N);
            for (int i = 0; i < N; ++i) {
                in >> m[i];
            }
            int y = 0, mx = 0, z = 0;
            for (int i = 1; i < N; ++i) {
                y += max(0, m[i - 1] - m[i]);
                mx = max(mx, m[i - 1] - m[i]);
            }
            for (int i = 0; i + 1 < N; ++i) {
                z += min(mx, m[i]);
            }
            out << "Case #" << t << ": " << y << " " << z << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_mushroom_monster solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
