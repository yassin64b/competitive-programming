#include <bits/stdc++.h>

using namespace std;

class abc088_c {
public:
    void solve(istream& in, ostream& out) {
        constexpr int n = 3;
        int c[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                in >> c[i][j];
            }
        }
        int a[3], b[3];
        for (a[0] = -1000; a[0] <= 1000; ++a[0]) {
            for (int i = 1; i < n; ++i) {
                a[i] = c[i][0] - c[0][0] + a[0];
            }
            for (int j = 0; j < n; ++j) {
                b[j] = c[0][j] - a[0];
            }
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (a[i] + b[j] != c[i][j]) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                out << "Yes\n";
                return;
            }
        }
        out << "No\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    abc088_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
