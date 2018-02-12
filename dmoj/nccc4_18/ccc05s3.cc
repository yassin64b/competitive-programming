#include <bits/stdc++.h>

using namespace std;

class ccc05s3 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        vector<vector<int>> a(1, vector<int>(1, 1));
        in >> N;
        for (int t = 0; t < N; ++t) {
            int r, c;
            in >> r >> c;
            vector<vector<int>> b(r, vector<int>(c));
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    in >> b[i][j];
                }
            }
            int n = a[0].size(), m = a.size();
            vector<vector<int>> res(m * r, vector<int>(n * c));
            for (int i = 0; i < m * r; i += r) {
                for (int j = 0; j < n * c; j += c) {
                    for (int k = i; k < i + r; ++k) {
                        for (int l = j; l < j + c; ++l) {
                            res[k][l] = a[i / r][j / c] * b[k - i][l - j];
                        }
                    }
                }
            }
            a = res;
        }
        constexpr int INF = 1'000'000'000;
        int mx = -INF, mn = INF, mx_row = -INF, mn_row = INF, mx_col = -INF, mn_col = INF;
        for (int i = 0; i < (int)a.size(); ++i) {
            for (int j = 0; j < (int)a[0].size(); ++j) {
                mx = max(mx, a[i][j]);
                mn = min(mn, a[i][j]);
            }
        }
        for (int i = 0; i < (int)a.size(); ++i) {
            int row = 0;
            for (int j = 0; j < (int)a[0].size(); ++j) {
                row += a[i][j];
            }
            mx_row = max(mx_row, row);
            mn_row = min(mn_row, row);
        }
        for (int j = 0; j < (int)a[0].size(); ++j) {
            int col = 0;
            for (int i = 0; i < (int)a.size(); ++i) {
                col += a[i][j];
            }
            mx_col = max(mx_col, col);
            mn_col = min(mn_col, col);
        }
        out << mx << "\n" << mn << "\n" << mx_row << "\n" << mn_row << "\n";
        out << mx_col << "\n" << mn_col << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    ccc05s3 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
