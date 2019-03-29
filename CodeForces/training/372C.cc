#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m), b(m), t(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> t[i];
    }
    constexpr i64 INF = 1e18;
    vector<i64> dp(n + 1, -INF);
    for (int j = 1; j <= n; ++j) dp[j] = 0;
    for (int i = 0; i < m; ++i) {
        i64 dist = 1LL * d * (t[i] - (i > 0 ? t[i - 1] : 1));
        deque<i64> mx;
        vector<i64> nxt(n + 1, -INF);
        for (int j = 1; j < 1 + dist && j <= n; ++j) {
            while (!mx.empty() && mx.back() < dp[j]) mx.pop_back();
            mx.push_back(dp[j]);
        }
        for (int j = 1; j <= n; ++j) {
            if (j - dist - 1 >= 1 && mx.front() == dp[j - dist - 1]) mx.pop_front();
            if (j + dist <= n) {
                while (!mx.empty() && mx.back() < dp[j + dist]) mx.pop_back();
                mx.push_back(dp[j + dist]);
            }
            i64 cur_mx = mx.front();
            nxt[j] = cur_mx + b[i] - abs(a[i] - j);
        }
        dp = nxt;
    }
    cout << *max_element(begin(dp), end(dp)) << "\n";

    return 0;
}