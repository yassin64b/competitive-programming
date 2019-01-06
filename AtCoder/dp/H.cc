#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }
    constexpr int MOD = 1'000'000'007;
    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i + 1 < H && grid[i + 1][j] != '#') {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            }
            if (j + 1 < W && grid[i][j + 1] != '#') {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
    }
    cout << dp[H - 1][W - 1] << "\n";

    return 0;
}