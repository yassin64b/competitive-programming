#include <bits/stdc++.h>

using namespace std;

class StonesOnATree {
public:
    int minStones(vector <int>, vector <int>);
};

void dfs(int u, const vector<vector<int>> &g, const vector<int> &w, vector<int> &dp) {
    dp[u] = w[u];
    for (int v : g[u]) {
        dfs(v, g, w, dp);
        dp[u] += w[v];
    }
    if (g[u].size() <= 1U) {
        for (int v : g[u]) {
            dp[u] = max(dp[u], dp[v]);
        }
        return;
    }
    int x = g[u][0], y = g[u][1];
    dp[u] = max(dp[u], min(max(dp[x], dp[y] + w[x]), max(dp[y], dp[x] + w[y])));
}

int StonesOnATree::minStones(vector <int> p, vector <int> w) {
    int n = w.size();
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        g[p[i]].push_back(i + 1);
    }
    vector<int> dp(n, 0);
    dfs(0, g, w, dp);
    return dp[0];
}