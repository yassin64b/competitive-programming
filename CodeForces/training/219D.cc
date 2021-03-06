#include <bits/stdc++.h>

using namespace std;

class D219 {
private:
    void dfs(int u, const vector<vector<pair<int, int>>> &g, vector<int> &vis,
            vector<int> &sub_inv)
    {
        vis[u] = 1;
        sub_inv[u] = 0;
        for (auto [v, inv] : g[u]) {
            if (!vis[v]) {
                sub_inv[u] += inv;
                dfs(v, g, vis, sub_inv);
                sub_inv[u] += sub_inv[v];
            }
        }
    }
    void dfs(int u, const vector<vector<pair<int, int>>> &g, vector<int> &vis,
            vector<int> &sub_inv, vector<int> &res)
    {
        vis[u] = 1;
        for (auto [v, inv] : g[u]) {
            if (!vis[v]) {
                res[v] = res[u] + (inv ? -1 : 1);
                dfs(v, g, vis, sub_inv, res);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int s, t;
            in >> s >> t;
            g[s - 1].emplace_back(t - 1, 0);
            g[t - 1].emplace_back(s - 1, 1);
        }
        vector<int> vis(n, 0), sub_inv(n, 0);
        dfs(0, g, vis, sub_inv);
        vector<int> res(n, 0);
        vis.assign(n, 0);
        res[0] = sub_inv[0];
        dfs(0, g, vis, sub_inv, res);
        int ans = *min_element(begin(res), end(res));
        out << ans << "\n";
        for (int u = 0; u < n; ++u) {
            if (res[u] == ans) {
                out << u + 1 << " ";
            }
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D219 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
