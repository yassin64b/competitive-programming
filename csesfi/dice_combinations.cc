#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    constexpr int MOD = 1'000'000'007;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 6 && i + j <= n; ++j) {
            dp[i + j] += dp[i];
            if (dp[i + j] >= MOD) {
                dp[i + j] -= MOD;
            }
        }
    }
    cout << dp[n] << "\n";

    return 0;
}