#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            in >> x[i] >> y[i];
        }
        int mnx = *min_element(begin(x), end(x));
        int mxx = *max_element(begin(x), end(x));
        int mny = *min_element(begin(y), end(y));
        int mxy = *max_element(begin(y), end(y));
        int f3 = 0;
        for (int i = 0; i < n; ++i) {
            int cur = 2 * max(x[i] - mnx, mxx - x[i]) + 2 * max(y[i] - mny, mxy - y[i]);
            f3 = max(f3, cur);
        }
        out << f3 << " ";
        int f4 = 2 * (mxx - mnx) + 2 * (mxy - mny);
        for (int i = 4; i <= n; ++i) {
            out << f4 << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
