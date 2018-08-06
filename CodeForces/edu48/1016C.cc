#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<i64>> g(2, vector<i64>(n));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                in >> g[i][j];
            }
        }
        vector<vector<i64>> sum1(2, vector<i64>(n + 1));
        vector<vector<i64>> sum2(2, vector<i64>(n + 1));
        vector<vector<i64>> sum3(2, vector<i64>(n + 1));
        for (int i = 0; i < 2; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                sum1[i][j] = g[i][j] + sum1[i][j + 1];
                sum2[i][j] = g[i][j] * j + sum2[i][j + 1];
                sum3[i][j] = g[i][j] * (n - j - 1) + sum3[i][j + 1];
            }
        }
        i64 cur = 0, res = 0;
        for (int i = 0, j = 0; j < n; ++j, i ^= 1) {
            i64 tmp = cur;
            tmp += j * sum1[i][j] + sum2[i][j];
            tmp += (j + n) * sum1[i ^ 1][j] + sum3[i ^ 1][j];
            res = max(res, tmp);
            cur += g[i][j] * (2 * j);
            cur += g[i ^ 1][j] * (2 * j + 1);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
