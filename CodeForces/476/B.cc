#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<string> field(n);
        for (int i = 0; i < n; ++i) {
            in >> field[i];
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        int mx = 0;
        int ri = 1, rj = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + k <= n) {
                    bool ok = true;
                    for (int ii = i; ok && ii < i + k; ++ii) {
                        ok = (field[ii][j] != '#');
                    }
                    for (int ii = i; ok && ii < i + k; ++ii) {
                        ++res[ii][j];
                        if (res[ii][j] > mx) {
                            ri = ii + 1;
                            rj = j + 1;
                            mx = res[ii][j];
                        }
                    }
                }
                if (j + k <= n) {
                    bool ok = true;
                    for (int jj = j; ok && jj < j + k; ++jj) {
                        ok = (field[i][jj] != '#');
                    }
                    for (int jj = j; ok && jj < j + k; ++jj) {
                        ++res[i][jj];
                        if (res[i][jj] > mx) {
                            ri = i + 1;
                            rj = jj + 1;
                            mx = res[i][jj];
                        }
                    }
                }
            }
        }
        out << ri << " " << rj << "\n";
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
