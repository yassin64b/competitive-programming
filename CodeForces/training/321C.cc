#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int par, const vector<vector<int>> &g, vector<int> &sz,
         const vector<bool> &erased) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (!erased[v] && v != par) {
            dfs(v, u, g, sz, erased);
            sz[u] += sz[v];
        }
    }
}

int centroid(int u, int par, int n, const vector<vector<int>> &g, 
              const vector<int> &sz, const vector<bool> &erased) {
    for (int v : g[u]) {
        if (v != par) {
            if (!erased[v] && sz[v] > n / 2)
                return centroid(v, u, n, g, sz, erased);
        }
    }
    return u;
}

void solve(int u, int col, vector<vector<int>> &g, 
           vector<int> &sz, vector<int> &res, vector<bool> &erased) {
    dfs(u, -1, g, sz, erased);
    int centr = centroid(u, -1, sz[u], g, sz, erased);
    res[centr] = col;
    erased[centr] = true;
    for (int v : g[centr]) {
        if (!erased[v])
            solve(v, col + 1, g, sz, res, erased);
    }    
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    vector<int> res(n, -1), sz(n, 0);
    vector<bool> erased(n, false);
    solve(0, 1, g, sz, res, erased);
    for (int u = 0; u < n; ++u) {
        cout << char(res[u] + 'A' - 1) << " ";
    }
    cout << "\n";

    return 0;
}