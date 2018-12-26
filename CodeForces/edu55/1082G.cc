#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class TaskG {
private:
    int dfs(int u, int t, int k, vector<vector<int>> &g, vector<vector<int>> &cap, vector<int> &vis, int id) {
        if (u == t) {
            return k;
        }
        vis[u] = id;
        for (int v : g[u]) {
            if (vis[v] != id && cap[u][v] >= k) {
                int add = dfs(v, t, k, g, cap, vis, id);
                if (add == k) {
                    cap[u][v] -= k;
                    cap[v][u] += k;
                    return add;
                }
            }
        }
        return 0;
    }
    i64 augment(int s, int t, int k, vector<vector<int>> &g, vector<vector<int>> &cap) {
        i64 cur = 0;
        int add = 1, it = 0;
        int n = g.size();
        vector<int> vis(n, 0);
        while (add) {
            add = dfs(s, t, k, g, cap, vis, ++it);
            cur += add;
        }
        return cur;
    }
    i64 maxflow(int s, int t, vector<vector<int>> &g, vector<vector<int>> &cap) {
        i64 flow = 0;
        for (int k = (1 << 29); k > 0; k >>= 1) {
            flow += augment(s, t, k, g, cap);
        }
        return flow;
    }
    void add_edge(int u, int v, int w, vector<vector<int>> &g, vector<vector<int>> &cap) {
        g[u].push_back(v);
        g[v].push_back(u);
        cap[u][v] += w;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        const int s = n + m, t = n + m + 1;
        constexpr int INF = 2'000'000'000;
        const int num = n + m + 2;
        i64 sum_w = 0;
        vector<vector<int>> cap(num, vector<int>(num, 0));
        vector<vector<int>> g(num);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            in >> u >> v >> w;
            --u;
            --v;
            sum_w += w;
            int e = n + i;
            add_edge(s, e, w, g, cap);
            add_edge(e, u, INF, g, cap);
            add_edge(e, v, INF, g, cap);
        }
        for (int u = 0; u < n; ++u) {
            add_edge(u, t, a[u], g, cap);
        }
        out << sum_w - maxflow(s, t, g, cap) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskG solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
