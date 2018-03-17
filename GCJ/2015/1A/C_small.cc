#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
    bool operator<(const point &o) {
        return x < o.x || (x == o.x && y < o.y);
    }
};

class gcj_logging {
private:
    is_left(const point &a, const point &b, const point &c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) > 0;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<point> p(N);
            for (int i = 0; i < N; ++i) {
                in >> p[i].x >> p[i].y;
            }
            out << "Case #" << t << ":\n";
            for (int i = 0; i < N; ++i) {
                int best = N - 1;
                for (int j = 0; j < N; ++j) {
                    if (i == j) continue;
                    int cur = 0;
                    for (int k = 0; k < N; ++k) {
                        if (i == k || j == k) continue;
                        if (is_left(p[k], p[i], p[j])) {
                            ++cur;
                        }
                    }
                    best = min(best, cur);
                }
                out << best << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_logging solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
