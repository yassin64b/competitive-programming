#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

// dp1 have one free for parent
// dp2 no free for parent
void dfs(int u, const vector<vector<pair<int, int>>> &g,
         vector<int> &vis, vector<i64> &dp1, vector<i64> &dp2,
         int k) {
    vis[u] = 1;
    vector<tuple<int, int, i64, i64>> ch;
    for (auto [v, w] : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis, dp1, dp2, k);
            ch.emplace_back(w, v, dp1[v], dp2[v]);
        }
    }
    sort(begin(ch), end(ch));
    reverse(begin(ch), end(ch));
    int num_ch = ch.size();
    if (num_ch <= k - 1) { // can all children
        for (auto [w, v, d1, d2] : ch) {
            dp1[u] += max(d1 + w, d2);
        }
    } else {
        sort(begin(ch), end(ch), [](const tuple<int, int, i64, i64> &l, const tuple<int, int, i64, i64> &r) {
            auto [w1, v1, d11, d21] = l;
            auto [w2, v2, d12, d22] = r;
            i64 vl = d11 + w1 - d21;
            i64 vr = d12 + w2 - d22;
            return vl > vr;
        });
        for (int i = 0; i < k; ++i) {
            auto [w, v, d1, d2] = ch[i];
            dp2[u] += max(d1 + w, d2);
        }
        for (int i = k; i < num_ch; ++i) {
            auto [w, v, d1, d2] = ch[i];
            dp2[u] += d2;
        }
        for (int i = 0; i < k - 1; ++i) {
            auto [w, v, d1, d2] = ch[i];
            dp1[u] += max(d1 + w, d2);
        }
        for (int i = k - 1; i < num_ch; ++i) {
            auto [w, v, d1, d2] = ch[i];
            dp1[u] += d2;
        }
    }
    dp2[u] = max(dp2[u], dp1[u]);
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k;
        cin >> n >> k;
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u - 1].emplace_back(v - 1, w);
            g[v - 1].emplace_back(u - 1, w);
        }
        vector<int> vis(n, 0);
        vector<i64> dp1(n, 0), dp2(n, 0);
        dfs(0, g, vis, dp1, dp2, k);
        cout << max(dp1[0], dp2[0]) << "\n";
    }
    return 0;
}