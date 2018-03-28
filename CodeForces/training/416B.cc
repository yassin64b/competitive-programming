#include <bits/stdc++.h>

using namespace std;

class B416 {
public:
    void solve(istream& in, ostream& out) {
        int m, n;
        in >> m >> n;
        vector<vector<int>> t(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                in >> t[i][j];
            }
        }
        vector<int> r(m, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                r[i] = max(((i > 0) ? r[i - 1] : 0), r[i]) + t[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            out << r[i] << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B416 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
