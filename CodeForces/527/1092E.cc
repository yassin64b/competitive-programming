#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    int dfs(int u, int p, int d, const vector<vector<int>> &g, vector<int> &dist, vector<int> &vis) {
        vis[u] = 1;
        dist[u] = d;
        int mx = u;
        for (int v : g[u]) {
            if (v != p) {
                int tmp = dfs(v, u, d + 1, g, dist, vis);
                if (dist[tmp] > dist[mx]) {
                    mx = tmp;
                }
            }
        }
        return mx;
    }
    pair<int, int> diam_center(int u, const vector<vector<int>> &g, vector<int> &vis) {
        vector<int> dist1(g.size(), -1), dist2(g.size(), - 1);
        int v1 = dfs(u, -1, 0, g, dist1, vis);
        int v2 = dfs(v1, -1, 0, g, dist2, vis);
        dfs(v2, -1, 0, g, dist1, vis);
        int d = dist2[v2];
        for (int c = 0; c < (int)g.size(); ++c) {
            if (dist2[c] == d / 2 && dist1[c] == d - d / 2) {
                return {d, c};
            }
        }
        return {-1, -1};
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        vector<pair<int, int>> t;
        vector<int> vis(n, 0);
        for (int u = 0; u < n; ++u) {
            if (!vis[u]) {
                t.emplace_back(diam_center(u, g, vis));
            }
        }
        sort(begin(t), end(t));
        reverse(begin(t), end(t));
        vector<pair<int, int>> e;
        for (int i = 1; i < (int)t.size(); ++i) {
            int u = t[0].second, v = t[i].second;
            e.emplace_back(u, v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        out << diam_center(0, g, vis).first << "\n";
        for (auto [u, v] : e) {
            out << u + 1 << " " << v + 1 << "\n";
        }
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