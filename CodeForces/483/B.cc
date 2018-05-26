#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<string> g(n);
        for (int i = 0; i < n; ++i) {
            in >> g[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isdigit(g[i][j])) {
                    for (int ii = max(i - 1, 0); ii <= i + 1 && ii < n; ++ii) {
                        for (int jj = max(j - 1, 0); jj <= j + 1 && jj < m; ++jj) {
                            if (g[ii][jj] == '*') {
                                --g[i][j];
                            }
                        }
                    }
                    if (g[i][j] != '0') {
                        out << "NO\n";
                        return;
                    }
                } else if (g[i][j] == '.') {
                    for (int ii = max(i - 1, 0); ii <= i + 1 && ii < n; ++ii) {
                        for (int jj = max(j - 1, 0); jj <= j + 1 && jj < m; ++jj) {
                            if (g[ii][jj] == '*') {
                                out << "NO\n";
                                return;
                            }
                        }
                    }
                }
            }
        }
        out << "YES\n";
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
