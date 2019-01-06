#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

void dfs(int u, int p, const vector<vector<int>> &g, vector<pair<int, int>> &dp) {
    dp[u].first = dp[u].second = 1;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u, g, dp);
            dp[u].first = (1LL * dp[u].first * (dp[v].first + dp[v].second)) % MOD;
            dp[u].second = (1LL * dp[u].second * dp[v].first) % MOD;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<vector<int>> g(N);
    for (int i = 0; i < N - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    
    vector<pair<int, int>> dp(N);
    dfs(0, -1, g, dp);
    cout << (dp[0].first + dp[0].second) % MOD << "\n";


    return 0;
}