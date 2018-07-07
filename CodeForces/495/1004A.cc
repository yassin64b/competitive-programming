#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, d;
        in >> n >> d;
        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            in >> x[i];
        }
        int res = 2;
        for (int i = 0; i + 1 < n; ++i) {
            int cur = x[i + 1] - x[i];
            if (cur == 2 * d) {
                ++res;
            } else if (cur > 2 * d) {
                res += 2;
            }
        }
        out << res << "\n";
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
