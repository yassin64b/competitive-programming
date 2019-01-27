#include <bits/stdc++.h>

using namespace std;

void dfs(int u, const vector<vector<int>> &g, vector<int> &vis, vector<int> &res) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis, res);
        }
    }
    res.push_back(u);
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1); 
        g[b - 1].push_back(a - 1);
    }
    vector<int> vis(n, 0), res;
    dfs(0, g, vis, res);

    for (int u : res) {
        cout << u + 1 << " ";
    }
    cout << "\n";


    return 0;
}