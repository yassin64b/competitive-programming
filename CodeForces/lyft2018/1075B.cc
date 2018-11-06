#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> x(n + m), t(n + m);
        for (int i = 0; i < n + m; ++i) {
            in >> x[i];
        }
        for (int i = 0; i < n + m; ++i) {
            in >> t[i];
        }
        vector<int> taxis, riders;
        for (int i = 0; i < n + m; ++i) {
            if (t[i]) {
                taxis.push_back(x[i]);
            } else {
                riders.push_back(x[i]);
            }
        }
        assert((int)taxis.size() == m);
        assert((int)riders.size() == n);
        sort(begin(taxis), end(taxis));
        sort(begin(riders), end(riders));
        vector<int> res(m, 0);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j + 1 < m && abs(taxis[j + 1] - riders[i]) < abs(taxis[j] - riders[i])) {
                ++j;
            }
            ++res[j];
        }
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
