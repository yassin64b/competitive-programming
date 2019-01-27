#include <bits/stdc++.h>

using namespace std;

void dfs(int u, const vector<vector<int>> &g, vector<int> &vis, 
         vector<int> &par, set<int> &desc) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis, par, desc);
        }
    }
    for (int v : g[u]) {
        if (!desc.count(v)) {
            par[v] = u;
            desc.insert(v);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    vector<int> indeg(N, 0);
    for (int i = 0; i < N - 1 + M; ++i) {
        int A, B;
        cin >> A >> B;
        g[A - 1].push_back(B - 1);
        ++indeg[B - 1];
    }
    int r = -1;
    for (int i = 0; i < N; ++i) {
        if (indeg[i] == 0) {
            r = i;
        }
    }

    vector<int> vis(N, 0), par(N, -1);
    set<int> desc;
    dfs(r, g, vis, par, desc);

    for (int i = 0; i < N; ++i) {
        cout << par[i] + 1 << "\n";
    }

    return 0;
}