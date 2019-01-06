#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    constexpr int MOD = 1'000'000'007;
    vector<int> dp(K + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        vector<int> nxt(K + 1, 0);
        for (int j = 0; j <= K; ++j) {
            nxt[j] = (nxt[j] + dp[j]) % MOD;
            if (j + a[i] + 1 <= K) {
                nxt[j + a[i] + 1] = (nxt[j + a[i] + 1] - dp[j] + MOD) % MOD;
            }
        }
        for (int j = 1; j <= K; ++j) {
            nxt[j] = (nxt[j] + nxt[j - 1]) % MOD;
        }
        dp = nxt;
    }
    cout << dp[K] << "\n";

    return 0;
}