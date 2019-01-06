#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }
    constexpr int INF = 1'000'000'001, MX = 100'000;
    vector<int> dp(MX + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = MX - v[i]; j >= 0; --j) {
            dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
        }
    }
    for (int j = MX; j >= 0; --j) {
        if (dp[j] <= W) {
            cout << j << "\n";
            return 0;
        }
    }
    return 0;
}