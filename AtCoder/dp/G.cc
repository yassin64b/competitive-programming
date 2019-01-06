#include <bits/stdc++.h>

using namespace std;

void dfs(int u, const vector<vector<int>> &g, vector<int> &vis, 
              vector<int> &top_sort) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis, top_sort);
        }
    }
    top_sort.push_back(u);
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N), rev_g(N);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        rev_g[y - 1].push_back(x - 1);
    }

    vector<int> top_sort, vis(N, 0);
    for (int u = 0; u < N; ++u) {
        if (!vis[u]) {
            dfs(u, rev_g, vis, top_sort);
        }
    }
    reverse(begin(top_sort), end(top_sort));
    vector<int> dp(N, 0);
    for (int u : top_sort) {
        for (int v : g[u]) {
            dp[u] = max(dp[u], dp[v] + 1);
        }
    }
    cout << *max_element(begin(dp), end(dp)) << "\n";

    return 0;
}