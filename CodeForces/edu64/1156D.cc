#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void dfs(int u, const vector<vector<int>> &g, vector<int> &vis,
        vector<int> &cur) {
    vis[u] = 1;
    cur.push_back(u);
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis, cur);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> g[2];
    g[0].resize(n);
    g[1].resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[c][x - 1].push_back(y - 1);
        g[c][y - 1].push_back(x - 1);
    }
    vector<int> cnt[2];
    cnt[0].resize(n);
    cnt[1].resize(n);
    i64 res = 0;
    for (int c = 0; c < 2; ++c) {
        vector<int> vis(n, 0);
        for (int u = 0; u < n; ++u) {
            if (!vis[u]) {
                vector<int> cur;
                dfs(u, g[c], vis, cur);
                int sz = cur.size();
                res += (i64)sz * (sz - 1);
                for (int v : cur) {
                    cnt[c][v] = sz - 1;
                }
            }
        }
    }
    for (int u = 0; u < n; ++u) {
        res += (i64)cnt[0][u] * cnt[1][u];
    }
    cout << res << "\n";

    return 0;
}