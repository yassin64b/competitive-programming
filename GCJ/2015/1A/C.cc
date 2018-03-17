#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
    bool operator<(const point &o) {
        return x < o.x || (x == o.x && y < o.y);
    }
};

constexpr double PI = 3.1415926535897932384626433832795028;
constexpr double EPS = 1e-9;

class gcj_logging {
private:
    // true iff point a is to the left line bc
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
                
                vector<double> angle;
                for (int j = 0; j < N; ++j) {
                    if (i != j) {
                        angle.push_back(atan2(p[j].y - p[i].y, p[j].x - p[i].x));
                    }
                }
                sort(begin(angle), end(angle));
                //angle.resize(2 * (N - 1));
                //copy_n(begin(angle), N - 1, begin(angle) + N - 1); // triggers assert for N=1
                for (int i = 0; i < N - 1; ++i) {
                    angle.push_back(angle[i]);
                }
                for (int i = N - 1; i < 2 * (N - 1); ++i) {
                    angle[i] += 2 * PI;
                }
                int tail = 0, head = 0;
                for (int j = 0; j < N - 1; ++j) {
                    while (tail + 1 < 2 * (N - 1)
                           && angle[tail + 1] - angle[j] < EPS)
                        ++tail;
                    //head = max(head, tail);
                    while (head + 1 < 2 * (N - 1) 
                           && angle[head + 1] - angle[j] < PI - EPS) 
                        ++head;
                    best = min(best, head - tail);
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
