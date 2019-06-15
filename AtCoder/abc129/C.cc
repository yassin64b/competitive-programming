#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> a(M), bl(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        cin >> a[i];
        bl[a[i]] = 1;
    }
    constexpr int MOD = 1'000'000'007;
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        if (i + 1 <= N && !bl[i + 1]) {
            dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
        }
        if (i + 2 <= N && !bl[i + 2]) {
            dp[i + 2] = (dp[i + 2] + dp[i]) % MOD;
        }
    }
    cout << dp[N] << "\n";

    return 0;
}