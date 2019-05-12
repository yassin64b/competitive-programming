#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

void dfs(int i, int j, vector<vector<pair<int, int>>> &dp, int n,
         vector<vector<int>> &vis) {
    if (i == 2 * n || vis[i][j]) {
        return;
    }
    vis[i][j] = 1;
    if (j < n) {
        dfs(i + 1, j + 1, dp, n, vis);
    }
    if (j > 0) {
        dfs(i + 1, j - 1, dp, n, vis);
    }
    bool oka = (j > 0 && dp[i + 1][j - 1].first >= 0);
    bool okb = (j < n && dp[i + 1][j + 1 ].first >= 0);
    if (oka && okb) {
        dp[i][j].first = dp[i + 1][j + 1].second + dp[i + 1][j - 1].second;
        dp[i][j].second = max(dp[i + 1][j + 1].second + dp[i + 1][j - 1].first + 1,
                              dp[i + 1][j + 1].first + 1 + dp[i + 1][j - 1].second);
    } else if (okb) { 
        dp[i][j].first = dp[i + 1][j + 1].second;
        dp[i][j].second = dp[i + 1][j + 1].first + 1;
    } else if (oka) { 
        dp[i][j].first = dp[i + 1][j - 1].second;
        dp[i][j].second = dp[i + 1][j - 1].first + 1;
    }
    dp[i][j].second = max(dp[i][j].second, dp[i][j].first);
    dp[i][j].first %= MOD; // -1 stays -1 under mod
    dp[i][j].second %= MOD;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> dp(2 * n + 1, 
                        vector<pair<int, int>>(n + 1, {-1, -1}));
    // dp[i][j] = max matching in subtree of depth i, balance j node
    // .first = subtree root node is free
    // .second = node is matched
    dp[2 * n][0] = {0, 0};
    vector<vector<int>> vis(2 * n + 1, vector<int>(n + 1, 0));
    dfs(0, 0, dp, n, vis);
    cout << dp[0][0].second << "\n";

    return 0;
}