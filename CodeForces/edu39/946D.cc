#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, m, k;
        in >> n >> m >> k;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            in >> grid[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    g[i].push_back(j);
                }
            }
        }
        vector<vector<int>> mx_save(n, vector<int>(k + 1, 0));
        for (int i = 0; i < n; ++i) {
            int len = g[i].size();
            if (len == 0) continue;
            int total_t = g[i].back() - g[i][0] + 1;
            if (len <= k && len > 0) {
                mx_save[i][len] = g[i].back() - g[i][0] + 1;
            }
            for (int a = 0; a + 1 < len && a + 1 <= k; ++a) {
                mx_save[i][a + 1] = max(mx_save[i][a + 1], g[i][a + 1] - g[i][0]);
            }
            for (int b = len - 1; b - 1 >= 0 && len - b <= k; --b) {
                mx_save[i][len - b] = max(mx_save[i][len - b], g[i].back() - g[i][b - 1]);
            }
            for (int a = 0; a + 1 < len; ++a) {
                for (int b = len - 1; b > a + 1; --b) {
                    int num = len - b + a + 1;
                    if (num <= k) {
                        mx_save[i][num] = max(mx_save[i][num], total_t - (g[i][b - 1] - g[i][a + 1] + 1));
                    }
                }
            }
        }
        vector<int> dp(k + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int a = k; a >= 0; --a) {
                for (int b = k; b >= 1; --b) {
                    if (a + b <= k) {
                        dp[a + b] = max(dp[a + b], dp[a] + mx_save[i][b]);
                    }
                }
            }
        }
        int total_time = 0;
        for (int i = 0; i < n; ++i) {
            if (!g[i].empty()) {
                total_time += g[i].back() - g[i][0] + 1;
            }
        }
        out << total_time - *max_element(begin(dp), end(dp)) << "\n";
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
