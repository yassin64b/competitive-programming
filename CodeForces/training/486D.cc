#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

class D486 {
private:
    void dfs(int u, const vector<vector<int>> &g, const vector<int> &a,
            vector<int> &vis, vector<int> &cnt, int mn, int mx, const vector<int> &done)
    {
        vis[u] = 1;
        cnt[u] = 1;
        for (int v : g[u]) {
            // last condition to avoid duplicate counting
            if (!vis[v] && a[v] >= mn && a[v] <= mx && (a[v] != mn || !done[v])) {
                dfs(v, g, a, vis, cnt, mn, mx, done);
                cnt[u] = (1LL * cnt[u] * (cnt[v] + 1)) % MOD;
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int d, n;
        in >> d >> n;
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
        vector<int> done(n, 0);
        int res = 0;
        for (int u = 0; u < n; ++u) {
            if (!done[u]) {
                vector<int> vis(n, 0), cnt(n, 0);
                int mn = a[u], mx = mn + d;
                dfs(u, g, a, vis, cnt, mn, mx, done);
                res = (res + cnt[u]) % MOD;
                done[u] = 1;
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D486 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
