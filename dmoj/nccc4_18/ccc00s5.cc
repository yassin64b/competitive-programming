#include <bits/stdc++.h>

using namespace std;

class ccc00s5 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<pair<double, double>> sheep(n);
        for (int i = 0; i < n; ++i) {
            in >> sheep[i].first >> sheep[i].second;
        }
        vector<int> eat(n, 0);
        for (double x = 0.00; x <= 1000.00; x += 0.01) {
            double mn_dist = 1e9;
            vector<int> ind;
            for (int i = 0; i < n; ++i) {
                double a = sheep[i].first, b = sheep[i].second;
                double dist = (a - x) * (a - x) + b * b;
                if (dist < mn_dist) {
                    ind.clear();
                    ind.push_back(i);
                    mn_dist = dist;
                } else if (dist == mn_dist) {
                    ind.push_back(i);
                }
            }
            for (int i : ind) {
                eat[i] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (eat[i]) {
                out.precision(2);
                out << fixed << "The sheep at (" << sheep[i].first << ", ";
                out << sheep[i].second << ") might be eaten.\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    ccc00s5 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
