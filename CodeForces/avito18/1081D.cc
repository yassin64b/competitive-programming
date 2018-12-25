#include <bits/stdc++.h>

using namespace std;

class TaskD {
private:
    void dfs(int u, const vector<vector<pair<int, int>>> &g, vector<int> &vis, int mx) {
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (!vis[v] && w <= mx) {
                dfs(v, g, vis, mx);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m, k;
        in >> n >> m >> k;
        vector<int> x(k);
        for (int i = 0; i < k; ++i) {
            in >> x[i];
            --x[i];
        }
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            in >> u >> v >> w;
            g[u - 1].emplace_back(v - 1, w);
            g[v - 1].emplace_back(u - 1, w);
        }
        int low = 1, high = 1'000'000'000, ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<int> vis(n, 0);
            dfs(x[0], g, vis, mid);
            bool ok = true;
            for (int i = 0; i < k; ++i) {
                if (!vis[x[i]]) {
                    ok = false;
                }
            }
            if (!ok) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        for (int i = 0; i < k; ++i) {
            out << ans << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
