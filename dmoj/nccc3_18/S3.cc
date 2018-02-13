#include <bits/stdc++.h>

using namespace std;

class nccc3j5s3 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> x(N), y(N);
        for (int i = 0; i < N; ++i) {
            in >> x[i] >> y[i];
        }
        if (N == 1) {
            out << 0 << "\n";
            return;
        }
        double res = 1e18;
        for (int a = 0; a < N; ++a) {
            for (int b = a + 1; b < N; ++b) {
                for (int c = b + 1; c < N; ++c) {
                    double y_delta_a = y[b] - y[a], x_delta_a = x[b] - x[a];
                    double y_delta_b = y[c] - y[b], x_delta_b = x[c] - x[b];
                    double cx = 0, cy = 0;
                    double a_slope = y_delta_a / x_delta_a, b_slope = y_delta_b / x_delta_b;
                    cx = (a_slope * b_slope * (y[a] - y[c]) + b_slope * (x[a] + x[b])
                        - a_slope * (x[b] + x[c])) / (2. * (b_slope - a_slope));
                    cy = -1. * (cx - (x[a] + x[b]) / 2.) / a_slope + (y[a] + y[b]) / 2.;
                    double r = 0;
                    for (int i = 0; i < N; ++i) {
                        double dist = sqrt((x[i] - cx) * (x[i] - cx) + (y[i] - cy) * (y[i] - cy));
                        r = max(r, dist);
                    }
                    res = min(res, r);
                }
            }
        }
        for (int a = 0; a < N; ++a) {
            for (int b = a + 1; b < N; ++b) {
                double cx = (x[a] + x[b]) / 2., cy = (y[a] + y[b]) / 2.;
                double r = 0;
                for (int i = 0; i < N; ++i) {
                    double dist = sqrt((x[i] - cx) * (x[i] - cx) + (y[i] - cy) * (y[i] - cy));
                    r = max(r, dist);
                }
                res = min(res, r);
            }
        }
        out.precision(17);
        out << fixed << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    nccc3j5s3 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
