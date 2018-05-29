#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    int dfs(int u, const vector<vector<int>> &g, vector<int> &vis) {
        vis[u] = 1;
        for (int v : g[u]) {
            if (!vis[v]) {
                return dfs(v, g, vis);
            }
        }
        return u;
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            in >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        int cnt = 0, r = 0;
        for (int u = 0; u < n; ++u) {
            if (g[u].size() > 2U) {
                ++cnt;
                r = u;
            }
        }
        if (cnt > 1) {
            out << "No\n";
            return;
        }
        vector<int> res, vis(n, 0);
        vis[r] = 1;
        for (int u : g[r]) {
            res.push_back(dfs(u, g, vis));
        }
        out << "Yes\n";
        out << res.size() << "\n";
        for (int v : res) {
            out << r + 1 << " " << v + 1 << "\n";
        }
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
