#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    void dfs(int u, const vector<vector<int>> &g, vector<int> &vis, int &sz, int &res) {
        vis[u] = 1;
        ++sz;
        for (int v : g[u]) {
            if (!vis[v]) {
                int ch_sz = 0, ch_res = 0;
                dfs(v, g, vis, ch_sz, ch_res);
                if (ch_sz % 2 == 0) {
                    ++res;
                } else {
                    sz += ch_sz;
                }
                res += ch_res;
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        if (n % 2) {
            out << -1 << "\n";
            return;
        }
        int r = 0;
        for (int u = 0; u < n; ++u) {
            if (g[u].size() == 1U) {
                r = u;
            }
        }
        int sz = 0, res = 0;
        vector<int> vis(n, 0);
        dfs(r, g, vis, sz, res);
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
