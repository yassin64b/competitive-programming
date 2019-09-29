#include <bits/stdc++.h>

using namespace std;

bool bfs(int r, const vector<vector<int>> &g, vector<int> &res) {
    queue<int> q;
    q.push(r);
    vector<int> vis(g.size(), 0), par(g.size(), -1);
    vis[r] = 1;
    par[r] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        bool ok = true;
        for (int v : g[u]) {
            if (v != r && vis[v] && vis[v] < vis[u]) {
                ok = false;
            }
        }
        if (!ok) continue;
        for (int v : g[u]) {
            if (v == r) {
                int cur = u;
                do {
                    res.push_back(cur);
                    cur = par[cur];
                } while (cur != -1);
                return true;
            }
        }
        for (int v : g[u]) {
            if (!vis[v]) {
                q.push(v);
                par[v] = u;
                vis[v] = vis[u] + 1;
            }
            
        }
    }
    return false;
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    for (int r = 0; r < N; ++r) {
        vector<int> res;
        if (bfs(r, g, res)) {
            cout << res.size() << "\n";
            for (int x : res) {
                cout << x + 1 << "\n";
            }
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}