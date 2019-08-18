#include <bits/stdc++.h>

using namespace std;

void dfs(int u, long long cur, const vector<vector<int>> &g,
         const vector<int> &add, vector<long long> &res, vector<int> &vis) {
    vis[u] = 1;
    cur += add[u];
    res[u] = cur;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, cur, g, add, res, vis);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> g(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b; 
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    vector<int> add(N, 0);
    for (int i = 0; i < Q; ++i) {
        int p, x;
        cin >> p >> x;
        add[p - 1] += x;
    }
    vector<long long> res(N, 0);
    vector<int> vis(N, 0);
    dfs(0, 0, g, add, res, vis);
    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}