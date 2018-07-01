#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    int dfs_cnt = 0;
    void dfs_bridge(int u, const vector<vector<pair<int, int>>> &g, set<pair<int, int>> &bridge,
                    vector<int> &low, vector<int> &num, vector<int> &par)
    {
        low[u] = num[u] = ++dfs_cnt;
        for (auto [v, w] : g[u]) {
            if (!num[v]) {
                par[v] = u;
                dfs_bridge(v, g, bridge, low, num, par);
                if (low[v] > num[u]) {
                    bridge.emplace(u, v);
                }
                low[u] = min(low[u], low[v]);
            } else if (v != par[u]) {
                low[u] = min(low[u], low[v]);
            }
        }
    }
    void dfs(int u, const vector<vector<pair<int, int>>> &g, vector<int> &dist) {
        for (auto [v, w] : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                dfs(v, g, dist);
            }
        }
    }
    int dfs(int u, int dest, const vector<vector<pair<int, int>>> &g, vector<int> &vis) {
        vis[u] = 1;
        if (u == dest) return 0;
        for (auto [v, w] : g[u]) {
            if (!vis[v]) {
                int tmp = dfs(v, dest, g, vis);
                if (tmp != -1) {
                    return tmp + w;
                }
            }
        }
        return -1;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0, x, y; i < m; ++i) {
            in >> x >> y;
            g[x - 1].emplace_back(y - 1, 0);
            g[y - 1].emplace_back(x - 1, 0);
        }
        set<pair<int, int>> bridge;
        vector<int> low(n), num(n, 0), par(n, -1);
        dfs_bridge(0, g, bridge, low, num, par);
        for (int u = 0; u < n; ++u) {
            for (auto &[v, w] : g[u]) {
                if (bridge.count(pair(u, v)) || bridge.count(pair(v, u))) {
                    w = 1;
                }
            }
        }
        vector<int> dist(n, -1);
        dist[0] = 0;
        dfs(0, g, dist);
        int s = max_element(begin(dist), end(dist)) - begin(dist);
        dist.assign(n, -1);
        dist[s] = 0;
        dfs(s, g, dist);
        int t = max_element(begin(dist), end(dist)) - begin(dist);
        vector<int> vis(n, 0);
        out << dfs(s, t, g, vis) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
