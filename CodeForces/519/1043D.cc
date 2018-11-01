#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<vector<int>> a(m, vector<int>(n)), inv(m, vector<int>(n + 1, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                in >> a[i][j];
                inv[i][a[i][j]] = j;
            }
        }
        long long res = 0;
        for (int i = 0, j = 0; i < n && j < n; ++i) {
            j = i;
            while (true) {
                if (j >= n - 1) {
                    long long len = j - i + 1;
                    res += len * (len + 1) / 2;
                    break;
                }
                bool ok = true;
                int v1 = a[0][j], v2 = a[0][j + 1];
                for (int k = 0; k < m; ++k) {
                    if (inv[k][v2] != inv[k][v1] + 1) {
                        ok = false;
                    }
                }
                if (!ok) {
                    long long len = j - i + 1;
                    res += len * (len + 1) / 2;
                    break;
                }
                ++j;
            }
            i = j;
        }
        out << res << "\n";
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
