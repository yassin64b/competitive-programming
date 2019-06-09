#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 998244353;

void dfs(int u, int lvl, int &res, const vector<vector<int>> &g,
         vector<int> &vis, const vector<int> &fac) {
    vis[u] = 1;
    int cntc = 0;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, lvl + 1, res, g, vis, fac);
            ++cntc;
        }
    }
    res = (1LL * res * fac[cntc]) % MOD;
    if (lvl > 0) { // split point left and right side of parent edge
        res = (1LL * res * (cntc + 1)) % MOD;
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    int res = n;
    vector<int> vis(n, 0);
    vector<int> fac(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    }
    dfs(0, 0, res, g, vis, fac);
    cout << res << "\n";

    return 0;
}