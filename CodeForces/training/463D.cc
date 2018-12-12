#include <bits/stdc++.h>

using namespace std;

class D463 {
private:
    void dfs(int u, const vector<vector<int>> &g, vector<int> &dp) {
        dp[u] = 1;
        for (int v : g[u]) {
            if (dp[v] == 0) {
                dfs(v, g, dp);
            }
            dp[u] = max(dp[u], dp[v] + 1);
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<vector<int>> p(k, vector<int>(n));
        vector<vector<int>> inv(k, vector<int>(n));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                in >> p[i][j];
                --p[i][j];
                inv[i][p[i][j]] = j;
            }
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool ok = true;
                for (int l = 0; l < k; ++l) {
                    if (inv[l][i] >= inv[l][j]) {
                        ok = false;
                    }
                }
                if (ok) {
                    g[i].push_back(j);
                }
            }
        }
        vector<int> dp(n, 0), in_deg(n, 0);
        for (int u = 0; u < n; ++u) {
            for (int v : g[u]) {
                ++in_deg[v];
            }
        }
        for (int u = 0; u < n; ++u) {
            if (in_deg[u] == 0) {
                dfs(u, g, dp);
            }
        }
        out << *max_element(begin(dp), end(dp)) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D463 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
