#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class TaskE {
private:
    void dfs(int u, const vector<vector<int>> &g, const vector<int> &a,
             vector<int> &vis, vector<i64> &cur, i64 &ans, int &k, bool cnt) {
        vis[u] = 1;
        cur[u] = a[u];
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, g, a, vis, cur, ans, k, cnt);
                cur[u] += max(cur[v], 0LL);
            }
        }
        if (cnt) {
            if (cur[u] == ans) {
                cur[u] = 0;
                ++k;
            }
        } else {
            ans = max(ans, cur[u]);
        }
    }
public:
    void solve(istream &in, ostream &out) {
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
        constexpr int INF = 1'000'000'001;
        i64 ans = -INF;
        int k = 0;
        vector<int> vis(n);
        vector<i64> cur(n);
        dfs(0, g, a, vis, cur, ans, k, false);
        vis.assign(n, 0);
        dfs(0, g, a, vis, cur, ans, k, true);
        out << ans * k << " " << k << "\n";
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
