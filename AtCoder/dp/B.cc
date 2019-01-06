#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }
    constexpr int INF = 1'000'000'000;
    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j <= i + K && j < N; ++j) {
            dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }
    cout << dp[N - 1] << "\n";

    return 0;
}