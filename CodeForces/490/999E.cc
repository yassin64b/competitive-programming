#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    void dfs(int u, const vector<vector<int>> &g, vector<int> &vis, vector<int> &l) {
        vis[u] = 1;
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, g, vis, l);
            }
        }
        l.push_back(u);
    }
    
    void dfs2(int u, int root, const vector<vector<int>> &g, vector<int> &comp) {
        comp[u] = root;
        for (int v : g[u]) {
            if (comp[v] == -1) {
                dfs2(v, root, g, comp);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m, s;
        in >> n >> m >> s;
        --s;
        vector<vector<int>> g(n), rg(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].push_back(v - 1);
            rg[v - 1].push_back(u - 1);
        }
        vector<int> vis(n, 0), l;
        for (int u = 0; u < n; ++u) {
            if (!vis[u]) {
                dfs(u, g, vis, l);
            }
        }
        reverse(begin(l), end(l));
        vector<int> comp(n, -1);
        for (int u : l) {
            if (comp[u] == -1) {
                dfs2(u, u, rg, comp);
            }
        }
        vector<int> res(n, -1);
        for (int u = 0; u < n; ++u) {
            if (res[comp[u]] == -1) {
                res[comp[u]] = 0;
            }
            for (int v : rg[u]) {
                if (comp[v] != comp[u]) {
                    res[comp[u]] = 1;
                }
            }
        }
        int ans = 0;
        for (int u = 0; u < n; ++u) {
            if (u != comp[s]) {
                ans += (res[u] == 0);
            }
        }
        out << ans << "\n";
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
