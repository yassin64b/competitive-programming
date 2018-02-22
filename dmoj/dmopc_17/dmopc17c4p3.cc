#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class dmopc17c4p3 {
private:
    void dfs(int u, const vector<vector<pair<int, int>>> &g,
            vector<vector<i64>> &dp, vector<int> &vis)
    {
        vis[u] = 1;
        dp[u][1] = dp[u][3] = dp[u][4] = u;
        i64 best_w = 0, node = -1;
        for (const auto &p : g[u]) {
            int v = p.first, w = p.second;
            if (!vis[v]) {
                dfs(v, g, dp, vis);
                if (dp[v][0] + w > dp[u][0]) {
                    dp[u][0] = dp[v][0] + w;
                    dp[u][1] = dp[v][1];
                }
                if (dp[v][2] > dp[u][2]) {
                    dp[u][2] = dp[v][2];
                    dp[u][3] = dp[v][3];
                    dp[u][4] = dp[v][4];
                }
                if (node != -1 && dp[v][0] + w + best_w > dp[u][2]) {
                    dp[u][2] = dp[v][0] + w + best_w;
                    dp[u][3] = dp[v][1];
                    dp[u][4] = node;
                }
                if (dp[v][0] + w > best_w) {
                    best_w = dp[v][0] + w;
                    node = dp[v][1];
                }
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<vector<pair<int, int>>> g(N);
        for (int i = 0; i < N - 1; ++i) {
            int a, b, c;
            in >> a >> b >> c;
            g[a - 1].emplace_back(b - 1, c);
            g[b - 1].emplace_back(a - 1, c);
        }
        vector<vector<i64>> dp(N, vector<i64>(5, 0));
        // dp[0,1]=weight,startnode
        // dp[2,3,4]=weight,startnode,endnode
        vector<int> vis(N, 0);
        dfs(0, g, dp, vis);
        if (dp[0][0] > dp[0][2]) {
            dp[0][2] = dp[0][0];
            dp[0][3] = 0;
            dp[0][4] = dp[0][1];
        }
        
        vector<vector<pair<int, int>>> g1(N), g2(N);
        for (int u = 0; u < N; ++u) {
            for (const auto &p : g[u]) {
                int v = p.first, w = p.second;
                if (u != dp[0][3] && v != dp[0][3]) {
                    g1[u].emplace_back(v, w);
                }
                if (u != dp[0][4] && v != dp[0][4]) {
                    g2[u].emplace_back(v, w);
                }
            }
        }
        vis.assign(N, 0);
        dp.assign(N, vector<i64>(5, 0));
        dfs(0, g1, dp, vis);
        i64 res = max(dp[0][0], dp[0][2]);
        
        vis.assign(N, 0);
        dp.assign(N, vector<i64>(5, 0));
        dfs(0, g2, dp, vis);
        res = max(res, max(dp[0][0], dp[0][2]));
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmopc17c4p3 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
