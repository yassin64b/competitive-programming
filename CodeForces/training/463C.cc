#include <bits/stdc++.h>

using namespace std;

class C463 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                in >> a[i][j];
            }
        }
        vector<long long> diag1(2 * n - 1), diag2(2 * n - 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                diag1[i + j] += a[i][j];
                diag2[i - j + n - 1] += a[i][j];
            }
        }
        long long mx[2]{-1, -1};
        int x[2], y[2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long val = diag1[i + j] + diag2[i - j + n - 1] - a[i][j];
                int ind = (i + j) % 2;
                if (val > mx[ind]) {
                    mx[ind] = val;
                    x[ind] = i + 1;
                    y[ind] = j + 1;
                }
            }
        }
        out << mx[0] + mx[1] << "\n" << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    C463 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
