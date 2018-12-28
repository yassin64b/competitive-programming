#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class TaskF {
private:
    void dfs(int u, int d, i64 &res, const vector<vector<int>> &g,
             const vector<int> &a, vector<int> &vis, vector<i64> &sub) {
        vis[u] = 1;
        res += 1LL * d * a[u];
        sub[u] = a[u];
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, d + 1, res, g, a, vis, sub);
                sub[u] += sub[v];
            }
        }
    }
    void dfs(int u, i64 cur, i64 &res, const vector<vector<int>> &g,
             const vector<int> &a, vector<int> &vis, vector<i64> &sub) {
        vis[u] = 1;
        res = max(res, cur);
        for (int v : g[u]) {
            if (!vis[v]) { // reroot at v
                i64 tmp = cur - sub[v];
                sub[u] -= sub[v];
                sub[v] += sub[u];
                tmp += sub[u];
                dfs(v, tmp, res, g, a, vis, sub);
                sub[v] -= sub[u];
                sub[u] += sub[v];
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        vector<i64> sub(n, 0);
        vector<int> vis(n, 0);
        i64 res = 0;
        dfs(0, 0, res, g, a, vis, sub);
        vis.assign(n, 0);
        dfs(0, res, res, g, a, vis, sub);
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskF solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
