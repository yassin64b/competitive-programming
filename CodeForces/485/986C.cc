#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    void dfs(int u, const vector<int> &g, vector<int> &vis) {
        vis[u] = 1;
        const int num = (1 << 22);
        if (u < num) {
            for (int j = 0; j < 22; ++j) {
                int v = (u | (1 << j));
                if (!vis[v]) {
                    dfs(v, g, vis);
                }
            }
            if (g[u] != -1 && !vis[g[u]]) {
                dfs(g[u], g, vis);
            }
        } else if (!vis[u - num]) {
            dfs(u - num, g, vis);
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            in >> a[i];
        }
        int num = (1 << 22);
        vector<int> g(num, -1);
        for (int i = 0; i < m; ++i) {
            int comp = num - 1 - a[i];
            g[comp] = a[i] + num;
        }
        int res = 0;
        vector<int> vis(2 * num, 0);
        for (int i = 0; i < m; ++i) {
            if (!vis[a[i] + num]) {
                dfs(a[i] + num, g, vis);
                ++res;
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
