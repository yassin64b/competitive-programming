#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    constexpr int MOD = 1'000'000'007;
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + c[j] <= x) {
                dp[i + c[j]] += dp[i];
                if (dp[i + c[j]] >= MOD) 
                    dp[i + c[j]] -= MOD;
            }
        }
    }
    cout << dp[x] << "\n";

    return 0;
}