#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    void dfs(int u, bool &ok, const vector<vector<int>> &g, vector<int> &vis) {
        vis[u] = 1;
        if (g[u].size() != 2U) {
            ok = false;
        }
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, ok, g, vis);
            }
        }
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
        int res = 0;
        vector<int> vis(n, 0);
        for (int u = 0; u < n; ++u) {
            if (!vis[u]) {
                bool ok = true;
                dfs(u, ok, g, vis);
                res += ok;
            }
        }
        out << res << "\n";
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
