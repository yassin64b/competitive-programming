#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<pair<int, int>> col_mx(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                col_mx[j].first = max(col_mx[j].first, a[i][j]);
                col_mx[j].second = j;
            }
        }
        sort(begin(col_mx), end(col_mx));
        reverse(begin(col_mx), end(col_mx));
        int newm = min(n, m);
        vector<vector<int>> b(n, vector<int>(newm));
        for (int j = 0; j < newm; ++j) {
            for (int i = 0; i < n; ++i) {
                b[i][j] = a[i][col_mx[j].second];
            }
        }
        m = newm;
        a = b;

        int k = (1 << n);
        vector<vector<int>> val(m, vector<int>(k));
        for (int j = 0; j < m; ++j) {
            for (int mask = 0; mask < k; ++mask) {
                for (int shift = 0; shift < n; ++shift) {
                    int cur = 0;
                    for (int i = 0; i < n; ++i) {
                        if (mask & (1 << i)) {
                            cur += a[(i + shift) % n][j];
                        }
                    }
                    val[j][mask] = max(val[j][mask], cur);
                }
            }
            
        }
        
        vector<vector<int>> dp(m + 1, vector<int>(k, 0));
        for (int j = 0; j < m; ++j) {
            for (int old_m = 0; old_m < k; ++old_m) {
                int inv_mask = (k - 1) & (~old_m);
                for (int mask = inv_mask; mask > 0; mask = (mask - 1) & inv_mask) {
                    dp[j + 1][old_m | mask] = max(dp[j + 1][old_m | mask],
                            dp[j][old_m] + val[j][mask]);
                }
                dp[j + 1][old_m] = max(dp[j + 1][old_m], dp[j][old_m] + val[j][0]);
            }
        }
        cout << dp[m][k - 1] << "\n";
    }
    return 0;
}