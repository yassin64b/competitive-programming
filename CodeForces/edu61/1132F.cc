#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n, vector<int>(n, 501));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }
    for (int k = 1; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
            int r = l + k;
            if (r >= n) continue;
            dp[l][r] = (s[l] == s[l + 1] ? 0 : 1) + dp[l + 1][r];
            for (int i = l + 2; i <= r; ++i) {
                if (s[l] == s[i]) {
                    dp[l][r] = min(dp[l][r], dp[l + 1][i - 1] + dp[i][r]);    
                }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";    
    
    return 0;
}