#include <bits/stdc++.h>

using namespace std;

class B107 {
public:
    void solve(istream& in, ostream& out) {
        int n, m, h;
        in >> n >> m >> h;
        --h;
        vector<int> s(m);
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            in >> s[i];
            sum += s[i];
        }
        if (sum < n) {
            out << -1 << "\n";
            return;
        }
        double res = 1.;
        for (int i = 0; i < n - 1; ++i) {
            res *= (double)(sum - s[h] - i) / (sum - 1 - i);
        }
        out.precision(7);
        out << fixed << 1. - res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B107 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
