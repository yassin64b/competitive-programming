#include <bits/stdc++.h>

using namespace std;

void bfs(int start, const vector<vector<int>> &g, vector<int> &dist) {
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

inline void common_path(int s1, int t1, int l1, int s2, int t2, int l2, int v1, int v2, 
                 const vector<vector<int>> &dist, int &res, int m) {
    int cur_l1 = dist[s1][v1] + dist[v1][v2] + dist[v2][t1];
    int cur_l2 = dist[s2][v1] + dist[v1][v2] + dist[v2][t2];
    if (cur_l1 <= l1 && cur_l2 <= l2) {
        res = max(res, m - (cur_l1 + cur_l2 - dist[v1][v2]));
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    --s1; --t1; --s2; --t2;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    for (int u = 0; u < n; ++u) {
        bfs(u, g, dist[u]);
    }
    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
        cout << -1 << "\n";
        return 0;
    }
    int res = m - (dist[s1][t1] + dist[s2][t2]); // disjoint paths
    for (int v1 = 0; v1 < n; ++v1) {
        for (int v2 = 0; v2 < n; ++v2) {
            // paths with common part from v1 to v2
            common_path(s1, t1, l1, s2, t2, l2, v1, v2, dist, res, m);
            common_path(t1, s1, l1, s2, t2, l2, v1, v2, dist, res, m);
        }
    }
    cout << res << "\n";

    return 0;
}