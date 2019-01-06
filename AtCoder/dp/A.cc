#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }
    constexpr int INF = 1'000'000'000;
    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        if (i + 1 < N) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        }
        if (i + 2 < N) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }
    cout << dp[N - 1] << "\n";

    return 0;
}