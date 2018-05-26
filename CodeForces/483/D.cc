#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            res[i][i] = a[i];
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                res[i][j] = res[i][j - 1] ^ res[i + 1][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res[i][j] = max(res[i][j], res[i][j - 1]);
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = j - 1; i >= 0; --i) {
                res[i][j] = max(res[i][j], res[i + 1][j]);
            }
        }
        int q;
        in >> q;
        for (int i = 0; i < q; ++i) {
            int l, r;
            in >> l >> r;
            out << res[l - 1][r - 1] << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
