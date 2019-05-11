#include <bits/stdc++.h>

using namespace std;

auto comp(string t) {
    int m2 = t.size();

    // nxt_ind[i][j] = at which ind of t we are after adding j at position i
    vector<vector<int>> nxt_ind(m2 + 1, vector<int>(26, 0));
    vector<vector<int>> add(m2 + 1, vector<int>(26, 0));
    for (int i = 0; i < m2; ++i) {
        for (int j = 0; j < 26; ++j) {
            char c = j + 'a';
            for (int len = 0; len <= i && len + 1 < m2; ++len) {
                string cur = t.substr(i - len, len) + c;
                bool ok = true;
                for (int k = 0; ok && k < len + 1; ++k) {
                    if (t[k] != cur[k]) {
                        ok = false;
                    }
                }
                if (ok) {
                    nxt_ind[i][j] = len + 1;
                }
            }
            if (i == m2 - 1 && c == t.back()) {
                add[i][j] = 1;
            }
        }
    }
    return pair(nxt_ind, add);
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string c, s, t;
    cin >> c >> s >> t;
    int n = c.size();
    int m1 = s.size(), m2 = t.size();
    auto [nxt_ind1, add1] = comp(s);
    auto [nxt_ind2, add2] = comp(t);

    constexpr int INF = 1'000'000;
    vector<vector<vector<int>>> dp(n + 1, 
        vector<vector<int>>(m1 + 1, vector<int>(m2 + 1, -INF)));
    // dp[i][j] = max value such that s fixed up to ind i
    // and we are at pos j in s and at pos k in t
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m1; ++j) {
            for (int k = 0; k < m2; ++k) {
                for (int a = 0; a < 26; ++a) {
                    if (c[i] == '*' || c[i] - 'a' == a) {
                        int val = dp[i][j][k] + add1[j][a] - add2[k][a];
                        int nj = nxt_ind1[j][a], nk = nxt_ind2[k][a];
                        dp[i+1][nj][nk] = max(dp[i+1][nj][nk], val);
                    }
                }
            }
        }
    }
    int res = -INF;
    for (int j = 0; j < m1; ++j) {
        for (int k = 0; k < m2; ++k) {
            res = max(res, dp[n][j][k]);
        }
    }
    cout << res << "\n";

    return 0;
}