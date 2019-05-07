#include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs(int u, const vector<vector<int>> &g, vector<int> &vis) {
    vis[u] = 1;
    int best = u, dist = 0;
    for (int v : g[u]) {
        if (!vis[v]) {
            //auto [x, d] = dfs(v, g, vis);
            auto p = dfs(v, g, vis);
            int x = p.first, d = p.second;
            if (d + 1 > dist) {
                dist = d + 1;
                best = x;
            }
        }
    }
    return {best, dist};
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<vector<int>> g(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<int> vis(N, 0);
    //auto [x, d] = dfs(0, g, vis);
    auto p = dfs(0, g, vis);
    int x = p.first;
    vis.assign(N, 0);
    //auto [y, diam] = dfs(x, g, vis);
    p = dfs(x, g, vis);
    int diam = p.second;

    // subtraction game with k = 2 in misere play
    // since diam == 0 is winning position
    cout << (diam % 3 == 1 ? "Second\n" : "First\n") << endl;

    return 0;
}