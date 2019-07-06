#include <bits/stdc++.h>

using namespace std;

// get 1 leaf in the subtree of u excluding p
int get_leaf(int u, int p, const vector<vector<pair<int, int>>> &g) {
    for (auto [v, w] : g[u]) {
        if (v != p) {
            return get_leaf(v, u, g);
        }
    }
    return u;
}

// get 2 leaves from the subtrees from 2 different children of u, excluding p
pair<int, int> get_leaves(int u, int p, const vector<vector<pair<int, int>>> &g) {
    if (g[u].size() == 1U) {
        return {u, u};
    }
    pair<int, int> l{-1, -1};
    for (auto [v, w] : g[u]) {
        if (v != p) {
            if (l.first == -1) {
                l.first = get_leaf(v, u, g);
            } else {
                l.second = get_leaf(v, u, g);
            }
        }
    }
    assert(l.first != -1 && l.second != -1);
    return l;
}

void dfs(int u, const vector<vector<pair<int, int>>> &g, vector<int> &vis,
         vector<tuple<int, int, int>> &res) {
    vis[u] = 1;
    for (auto [v, w] : g[u]) {
        if (!vis[v]) {
            auto [a, b] = get_leaves(u, v, g);
            auto [c, d] = get_leaves(v, u, g);
            res.emplace_back(a, c, w / 2);
            res.emplace_back(b, d, w / 2);
            if (a != b) res.emplace_back(a, b, -w / 2);
            else assert(a == u);
            if (c != d) res.emplace_back(c, d, -w / 2);
            else assert(c == v);

            dfs(v, g, vis, res);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].emplace_back(v - 1, w);
        g[v - 1].emplace_back(u - 1, w);
    }
    for (int u = 0; u < n; ++u) {
        if (g[u].size() == 2U) {
            cout << "NO\n";
            return 0;
        }
    }
    vector<tuple<int, int, int>> ops;
    vector<int> vis(n, 0);
    dfs(0, g, vis, ops);

    cout << "YES\n" << ops.size() << "\n";
    for (const auto &[u, v, x] : ops) {
        cout << u + 1 << " " << v + 1 << " " << x << "\n";
    }

    return 0;
}