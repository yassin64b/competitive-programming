#include <bits/stdc++.h>

using namespace std;

int solve(int start, int end, int n, int MOD, int k) {
    // count no of ways s.t. every two consecutive elements are not equal
    // dp1 = no of ways s.t. cur el is not equal to end
    int dp1 = k - (start != 0) - (end != -1) + (start == end);
    // dp2 = no of ways s.t. cur el equal to end
    int dp2 = 1 - (start == end) - (end == -1);
    for (int i = 1; i < n; ++i) {
        int nxt1 = (1LL * dp2 * (k - 1) + 1LL * dp1 * (k - 1 - (end != -1))) % MOD;
        int nxt2 = (end == -1 ? 0 : dp1);
        dp1 = nxt1;
        dp2 = nxt2;
    }
    return dp1;
}


int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    constexpr int MOD = 998244353;

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> v(2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[i % 2].push_back(a[i]);
    }
    for (int i = 0; i + 2 < n; ++i) {
        if (a[i] == a[i + 2] && a[i] != -1) {
            cout << 0 << "\n";
            return 0;
        }
    }
    int res = 1;
    for (const auto &w : v) {
        int m = w.size();
        for (int i = 0; i < m; ) {
            if (w[i] == -1) {
                int start = (i > 0 ? w[i - 1] : 0), cnt = 0;
                while (i < m && w[i] == -1) {
                    ++cnt;
                    ++i;
                }
                int end = (i < m ? w[i] : -1);
                res = (1LL * res * solve(start, end, cnt, MOD, k)) % MOD;
            } else {
                ++i;
            }
        }
    }
    cout << res << "\n";

    return 0;
}