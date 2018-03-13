#include <bits/stdc++.h>

using namespace std;

class yndx_b {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        constexpr long long MUL = 1000000000;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            in >> b[i];
        }
        int first_mx_row = 0, last_mx_row = 0;
        int mx_col = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > a[first_mx_row]) first_mx_row = i;
            if (a[i] >= a[last_mx_row]) last_mx_row = i;
        }
        for (int i = 0; i < m; ++i) {
            if (b[i] > b[mx_col]) mx_col = i;
        }
        long long res = 0;
        for (int i = 0; i <= first_mx_row; ++i) res += a[i] * MUL + b[0];
        for (int j = 1; j <= mx_col; ++j) res += a[first_mx_row] * MUL + b[j];
        for (int i = first_mx_row + 1; i <= last_mx_row; ++i) res += a[i] * MUL + b[mx_col];
        for (int j = mx_col + 1; j < m; ++j) res += a[last_mx_row] * MUL + b[j];
        for (int i = last_mx_row + 1; i < n; ++i) res += a[i] * MUL + b[m - 1];
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    yndx_b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
