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

    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = W - w[i]; j >= 0; --j) {
            dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
        }
    }
    cout << *max_element(begin(dp), end(dp)) << "\n";
    return 0;
}