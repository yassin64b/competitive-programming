#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, m, k, s;
        in >> n >> m >> k >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        vector<vector<int>> res(n);
        for (int i = 1; i <= k; ++i) {
            vector<int> dist(n, -1);
            queue<int> q;
            for (int u = 0; u < n; ++u) {
                if (a[u] == i) {
                    dist[u] = 0;
                    q.push(u);
                }
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            for (int u = 0; u < n; ++u) {
                res[u].push_back(dist[u]);
            }
        }
        for (int u = 0; u < n; ++u) {
            sort(begin(res[u]), end(res[u]));
            long long ans = 0;
            for (int i = 0; i < s; ++i) {
                ans += res[u][i];
            }
            out << ans << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
