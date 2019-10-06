#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> adj(N);
    for (int i = 0; i < N; ++i) {
        cin >> adj[i];
    }
    vector<vector<int>> g(N);
    int m = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (adj[i][j] == '1') {
                g[i].push_back(j);
                g[j].push_back(i);
                ++m;
            }
        }
    }
    int mx_res = -1;
    for (int u = 0; u < N; ++u) {
        vector<vector<int>> res;
        res.push_back({u});
        vector<int> vis(N, 0);
        vis[u] = 1;
        int i = 0;
        bool ok = true;
        while (i < (int)res.size()) {
            vector<int> tmp;
            for (int v : res[i]) {
                for (int w : g[v]) {
                    if (!vis[w]) {
                        tmp.push_back(w);
                        vis[w] = i + 2;
                    } else if (vis[w] != i && vis[w] != i + 2) {
                        ok = false;
                    }
                }
            }
            if (!tmp.empty()) {
                res.push_back(tmp);
            }
            ++i;
        }
        if (ok) {
            mx_res = max(mx_res, (int)res.size());
        }
    }
    cout << mx_res << "\n";

    return 0;
}