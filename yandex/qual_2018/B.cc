#include <bits/stdc++.h>

using namespace std;

class yandex_B {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> m(2 * n, vector<int>(n));
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < n; ++j) {
                in >> m[i][j];
            }
        }
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < 2 * n; ++i) {
            res[0] = m[i];
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                ok = false;
                for (int k = 0; !ok && k < 2 * n; ++k) {
                    if (k != i && m[k][0] == res[0][j]) {
                        for (int l = 0; l < n; ++l) {
                            res[l][j] = m[k][l];
                        }
                        ok = true;
                    }
                }
                if (!ok) {
                    break;
                }
            }
            if (ok) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        out << res[j][k] << " ";
                    }
                }
                out << "\n";
                return;
            }
        }
        assert(false);
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    yandex_B solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
