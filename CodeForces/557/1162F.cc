#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 998'244'353;

void add_edge(int u, int v, int w, vector<vector<pair<int, int>>> &g) {
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
}

void dfs(int u, const vector<vector<pair<int, int>>> &g, vector<int> &vis,
         vector<int> &col, bool &ok) {
    vis[u] = 1;
    for (auto [v, w] : g[u]) {
        if (!vis[v]) {
            col[v] = (col[u] ^ w);
            dfs(v, g, vis, col, ok);
        } else if (col[v] != (col[u] ^ w)) {
            ok = false;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size();
    int res = 0;
    for (int k = 0; k < n; ++k) { // length of a
        int m = n + k;
        vector<vector<pair<int, int>>> g(m + 1);
        // first n nodes are the bits of b
        // next k nodes are the bits of a
        // last node is a fixed 0 bit node
        // 0-edge means nodes have to have same bit
        // 1-edge means nodes have to have different bit
        for (int i = 0; i < n - i - 1; ++i) { // palindrome constraint b
            add_edge(i, n - i - 1, 0, g);
        }
        for (int i = 0; i < k - i - 1; ++i) { // palindrome constraint a
            add_edge(i + n, k - i - 1 + n, 0, g);
        }
        for (int i = n - 1, j = n + k - 1; i >= 0; --i, --j) {
            if (s[i] != '?') {
                if (j >= n) {
                    // a[i] and b[i] have to same/different dep. on s
                    add_edge(i, j, (s[i] == '1'), g);
                } else {
                    // if a already ended
                    // b[i] has to be 0 or 1 fixed depending on s
                    add_edge(i, m, (s[i] == '1'), g);
                }
            }
        }
        // a also has to start with 1 bit (no leading zeroes)
        // (b starts with 1 because s[0] == 1)
        add_edge(0, n, 0, g);

        int cnt = 0;
        bool ok = true;
        vector<int> vis(m + 1, 0), col(m + 1, 0);
        for (int i = 0; i <= m; ++i) {
            if (!vis[i]) {
                ++cnt;
                dfs(i, g, vis, col, ok);
            }
        }
        if (!ok) { // not bipartite --> not satisfiable
            continue;
        }
        int add = 1;
        for (int i = 0; i < cnt - 1; ++i) { // subtract 1 for fixed component of node m
            add = 2 * add % MOD;
        }
        res = (res + add) % MOD;
    }
    cout << res << "\n";

    return 0;
}