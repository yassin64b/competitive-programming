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
    vector<pair<int, int>> dp(K + 1, {0, 0});
    for (int i = 0; i <= K; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i - a[j] >= 0) {
                if (dp[i - a[j]].second == 0) {
                    dp[i].first = 1;
                }
                if (dp[i - a[j]].first == 0) {
                    dp[i].second = 1;
                }
            }
        }
    }
    cout << (dp[K].first ? "First" : "Second") << "\n";

    return 0;
}