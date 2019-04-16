#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    vector<int> mx_offer(k + 1, 0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if (x <= k) {
            mx_offer[x] = max(mx_offer[x], y);
        }
    }
    
    sort(begin(a), end(a));
    a.resize(k);
    reverse(begin(a), end(a));

    vector<int> pre_sum(begin(a), end(a));
    for (int i = 1; i < k; ++i) {
        pre_sum[i] += pre_sum[i - 1];
    }

    constexpr int INF = 1'000'000'000;
    vector<int> dp(k + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < k; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + a[i]);
        for (int j = 1; i + j <= k; ++j) {
            int end_t = i + j - 1;
            int ctotal = pre_sum[end_t] - (i > 0 ? pre_sum[i - 1] : 0);
            int beg_f = end_t - mx_offer[j] + 1;
            int cfree = pre_sum[end_t] - (beg_f > 0 ? pre_sum[beg_f - 1] : 0);
            dp[i + j] = min(dp[i + j], dp[i] + ctotal - cfree);
        }
    }
    cout << dp[k] << "\n";

    return 0;
}