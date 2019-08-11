#include <bits/stdc++.h>

using namespace std;

void dfs(int u, const vector<vector<pair<int, int>>> &g, vector<int> &vis) {
    vis[u] = 1;
    for (const auto p : g[u]) {
        int v = p.first, c = p.second;
        if (!vis[v]) {
            dfs(v, g, vis);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, M, P;
    cin >> N >> M >> P;
    vector<vector<pair<int, int>>> g(N);
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        g[A - 1].emplace_back(B - 1, -(C - P));
    }
    vector<int> rem(N, 0);
    for (int u = 1; u < N; ++u) {
        vector<int> vis(N, 0);
        dfs(u, g, vis);
        if (!vis[N - 1]) {
            rem[u] = 1;
        }
    }
    {
        vector<int> vis(N, 0);
        dfs(0, g, vis);
        for (int u = 1; u < N; ++u) {
            if (!vis[u]) {
                rem[u] = 1;
            }
        }
    }

    vector<int> dist(N, 1'000'000'000), par(N, -1);
    dist[0] = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int u = 0; u < N; ++u) {
            if (rem[u]) continue;
            for (const auto p : g[u]) {
                int v = p.first, c = p.second;
                if (rem[v]) continue;
                if (dist[u] + c < dist[v]) {
                    dist[v] = dist[u] + c;
                    par[v] = u;
                }
            }
        }
    }
    for (int u = 0; u < N; ++u) {
        if (rem[u]) continue;
        for (const auto p : g[u]) {
            int v = p.first, c = p.second;
            if (rem[v]) continue;
            if (dist[u] + c < dist[v]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << max(-dist[N - 1], 0) << "\n";

    return 0;
}