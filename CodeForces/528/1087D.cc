#include <bits/stdc++.h>

using namespace std;

class D1087 {
public:
    void solve(istream& in, ostream& out) {
        int n, s;
        in >> n >> s;
        vector<vector<int>> g(n);
        for (int i = 0, a, b; i < n - 1; ++i) {
            in >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        int num_leaves = 0;
        for (int u = 0; u < n; ++u) {
            num_leaves += (g[u].size() == 1U);
        }
        double min_diam = 2. * s / num_leaves;
        out.precision(11);
        out << fixed << min_diam << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D1087 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
