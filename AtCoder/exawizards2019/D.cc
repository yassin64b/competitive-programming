#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N, X;
    cin >> N >> X;
    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    sort(begin(S), end(S));

    constexpr int MOD = 1'000'000'007;
    vector<vector<int>> dp(N + 1, vector<int>(X + 1, 0));
    for (int x = 0; x <= X; ++x) 
        dp[0][x] = x;
    for (int i = 0; i < N; ++i) {
        for (int x = 0; x <= X; ++x) {
            dp[i + 1][x] = (dp[i][x % S[i]] + 1LL * dp[i][x] * i) % MOD;
        }
    }

    int res = dp[N][X];
    cout << res << "\n";

    return 0;
}