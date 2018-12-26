#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int n, x, y, d;
            in >> n >> x >> y >> d;
            constexpr int INF = 2'000'000'001;
            int ans = INF;
            if (abs(y - x) % d == 0) {
                ans = abs(y - x) / d;
            }
            if ((y - 1) % d == 0) {
                ans = min(ans, (x - 1 + d - 1) / d + (y - 1) / d);
            }
            if ((n - y) % d == 0) {
                ans = min(ans, (n - x + d - 1) / d + (n - y) / d);
            }
            out << (ans == INF ? -1 : ans) << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
