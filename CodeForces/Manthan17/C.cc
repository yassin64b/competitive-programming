#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    static constexpr int MOD = 1'000'000'007;
    void dfs(int u, const vector<vector<int>> &g, vector<int> &vis,
            vector<vector<vector<long long>>> &dp, const int x, const int m, const int k)
    {
        vis[u] = 1;
        int num = 0;
        // local_dp[j][k] = num ways to arrive at type k with j vaults and self (u)
        // compute iteratively over first i neighbors
        vector<vector<long long>> local_dp(x + 1, vector<long long>(3, 0));
        local_dp[0][1] = local_dp[0][2] = 1;
        local_dp[1][0] = 1;
        for (int v : g[u]) {
            if (!vis[v]) {
                ++num;
                dfs(v, g, vis, dp, x, m, k);
                
                vector<vector<long long>> local_nxt(x + 1, vector<long long>(3, 0));
                for (int l = 0; l <= x; ++l) { // l no. max vaults covered by previous neighbors and self (u)
                    for (int r = 0; l + r <= x; ++r) { // r new vaults covered by current neighbor v
                        local_nxt[l + r][2] += local_dp[l][2] * ((dp[v][r][0] + dp[v][r][1] + dp[v][r][2]));
                        local_nxt[l + r][2] %= MOD;
                        
                        local_nxt[l + r][0] += local_dp[l][0] * (dp[v][r][2]);
                        local_nxt[l + r][0] %= MOD;
                        
                        local_nxt[l + r][1] += local_dp[l][1] * ((dp[v][r][1] + dp[v][r][2]));
                        local_nxt[l + r][1] %= MOD;
                    }
                }
                local_dp = local_nxt;
            }
        }
        if (num == 0) {
            dp[u][1][0] = 1;
            dp[u][0][1] = m - k;
            dp[u][0][2] = k - 1;
        } else {
            for (int l = 0; l <= x; ++l) {
                dp[u][l][2] = local_dp[l][2] * (k - 1);
                dp[u][l][2] %= MOD;
                
                dp[u][l][0] = local_dp[l][0] * 1;
                dp[u][l][0] %= MOD;
                
                dp[u][l][1] = local_dp[l][1] * (m - k);
                dp[u][l][1] %= MOD;
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        int k, x;
        in >> k >> x;
        // dp[i][j][x] = number of ways in subtree of node i with j max vaults
        // z=0 with i as max vault, z=1 with vault value > k, z=2 with vault value < k
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(x + 1, vector<long long>(3, 0)));
        vector<int> vis(n, 0);
        dfs(0, g, vis, dp, x, m, k);
        int res = 0;
        for (int i = 0; i <= x; ++i) {
            for (int z = 0; z < 3; ++z) {
                res += dp[0][i][z];
                res %= MOD;
            }
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
