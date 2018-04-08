class Solution {
public:
    string longestPalindrome(string c) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int mx_len = 1;
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            if (i + 1 < n && c[i] == c[i + 1]) {
                dp[i][i + 1] = 1;
                mx_len = 2;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                if (c[i] == c[i + len - 1] && dp[i + 1][i + len - 2]) {
                    dp[i][i + len - 1] = 1;
                    mx_len = len;
                }
            }
        }
        for (int i = 0; i + mx_len <= n; ++i) {
            if (dp[i][i + mx_len - 1]) {
                return c.substr(i, mx_len);
            }
        }
    }
};


