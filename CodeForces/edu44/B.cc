#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        vector<int> b(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                in >> a[i][j];
                b[j] += (a[i][j] - '0');
            }
        }
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < m; ++j) {
                b[j] -= (a[i][j] - '0');
                if (!b[j]) {
                    ok = false;
                }
            }
            if (ok) {
                out << "YES\n";
                return;
            } else {
                for (int j = 0; j < m; ++j) {
                    b[j] += (a[i][j] - '0');
                }
            }
        }
        out << "NO\n";
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
