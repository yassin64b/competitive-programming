#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i < n && j < m && s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            if (i < n) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
            if (j < m) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            }
        }
    }

    string lcs;
    int i = n, j = m;
    while (i != 0 || j != 0) {
        assert(i - 1 < n && j - 1 < m);
        if (i > 0 && j > 0 && s[i - 1] == t[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1) {
            lcs += s[i - 1];
            --i;
            --j;
        } else if (i > 0 && dp[i][j] == dp[i - 1][j]) {
            --i;
        } else if (j > 0 && dp[i][j] == dp[i][j - 1]) {
            --j;
        } else {
            assert(false);
        }
    }
    reverse(begin(lcs), end(lcs));
    cout << lcs << "\n";

    return 0;
}