#include <bits/stdc++.h>

using namespace std;

void dfs(int u, const vector<vector<int>> &g, vector<int> &vis,
         int &mn, int &mx) {
    vis[u] = 1;
    mn = min(mn, u);
    mx = max(mx, u);
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis, mn, mx);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    vector<pair<int, int>> segs;
    vector<int> vis(n, 0);
    int conn_comps = 0;
    for (int u = 0; u < n; ++u) {
        if (!vis[u]) {
            ++conn_comps;
            int mn = u, mx = u;
            dfs(u, g, vis, mn, mx);
            segs.emplace_back(mn, mx);
        }
    }
    sort(begin(segs), end(segs));
    int non_overlap = 0;
    int upto = -1;
    for (int i = 0; i < (int)segs.size(); ++i) {
        if (upto < segs[i].first) {
            ++non_overlap;
        }
        upto = max(upto, segs[i].second);
    }
    cout << conn_comps - non_overlap << "\n";
    return 0;
}