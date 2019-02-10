#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++b[a[i]];
    }
    vector<vector<int>> dp(10, vector<int>(10));
    for (int i = 1; i + 2 <= m; ++i) {
        vector<vector<int>> nxt(10, vector<int>(10));
        for (int x1 = 0; x1 < 10 && x1 <= b[i]; ++x1) {
            for (int x2 = 0; x1 + x2 < 10 && x1 + x2 <= b[i]; ++x2) {
                for (int x3 = 0; x1 + x3 < 10 && x1 + x3 <= b[i + 1] && x1 <= b[i + 2]; ++x3) {
                    nxt[x1 + x3][x1] = max(nxt[x1 + x3][x1], 
                                           dp[x2][x3] + x1 + (b[i] - (x1 + x2)) / 3);
                    // x2, x3, 0 --> x1 + x2, x1 + x3, x1
                }
            }
        }
        dp = nxt;
    }
    
    int res = 0;
    for (int x2 = 0; x2 < 10; ++x2) {
        for (int x3 = 0; x3 < 10; ++x3) {
            dp[x2][x3] += (b[m - 1] - x2) / 3 + (b[m] - x3) / 3;
            res = max(res, dp[x2][x3]);
        }
    }

    cout << res << "\n";


    return 0;
}