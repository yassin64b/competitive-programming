#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    void dfs(int u, const vector<vector<int>> &g, vector<int> &vis, int from, int &cnt, bool ok) {
        if (u == from) {
            ok = true;
        }
        cnt += ok;
        vis[u] = 1;
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, g, vis, from, cnt, ok);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, x, y;
        in >> n >> x >> y;
        --x;
        --y;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            in >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        int cnt1 = 0, cnt2 = 0;
        vector<int> vis(n, 0);
        dfs(y, g, vis, x, cnt1, false);
        vis.assign(n, 0);
        dfs(x, g, vis, y, cnt2, false);
        out << 1LL * n * (n - 1) - 1LL * cnt1 * cnt2 << "\n";
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
