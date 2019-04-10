#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<tuple<int, int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        g[u - 1].emplace_back(v - 1, x, 0);
        g[v - 1].emplace_back(u - 1, x, 0);
    }
    for (int i = 0; i < k; ++i) {
        int s, y;
        cin >> s >> y;
        g[0].emplace_back(s - 1, y, 1);
    }
    constexpr i64 INF = 1e18;
    vector<i64> dist(n, INF);
    priority_queue<pair<i64, int>> pq;
    pq.emplace(-0, 0);
    dist[0] = 0;
    while (!pq.empty()) {
        i64 d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (const auto &[v, x, t] : g[u]) {
            i64 nd = d + x;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(-dist[v], v);
            }
        }
    }
    int res = k;
    vector<pair<int, int>> cnt(n);
    for (int u = 0; u < n; ++u) {
        for (const auto &[v, x, t] : g[u]) {
            if (dist[v] == dist[u] + x) {
                cnt[v].first += (t == 0);
                cnt[v].second += (t == 1);
                res -= (t == 1);
            }
        }
    }
    for (int u = 0; u < n; ++u) {
        if (cnt[u].first) {
            res += cnt[u].second;
        } else {
            res += max(0, cnt[u].second - 1);
        }
    }
    cout << res << "\n";

    return 0;
}