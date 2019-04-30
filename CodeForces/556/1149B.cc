#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    string univ;
    cin >> univ;
    vector<vector<int>> nxt_occ(n + 2, vector<int>(26, n));
    for (int i = n - 1; i >= 0; --i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (univ[i] == c) {
                nxt_occ[i][c - 'a'] = i;
            } else {
                nxt_occ[i][c - 'a'] = nxt_occ[i + 1][c - 'a'];
            }
        }
    }
    constexpr int MXL = 251;
    vector<vector<vector<int>>> dp(MXL, vector<vector<int>>(MXL, vector<int>(MXL, n)));
    // dp[i][j][k] = min len prefix of univ s.t. s1/s2/s3 are contained disjointly up to i/j/k
    dp[0][0][0] = 0;
    int m[3]{0, 0, 0};
    string s[3];
    for (int i = 0; i < q; ++i) {
        char type;
        int ind;
        cin >> type >> ind;
        --ind;
        if (type == '+') {
            char c;
            cin >> c;
            ++m[ind];
            s[ind] += c;
            for (int x = 0; x < MXL; ++x) {
                for (int y = 0; y < MXL; ++y) {
                    int z = m[ind];
                    if (ind == 0 && x <= m[1] && y <= m[2]) {
                        dp[z][x][y] = nxt_occ[dp[z-1][x][y]][s[0].back()-'a']+1;
                        if (x > 0)
                            dp[z][x][y] = min(nxt_occ[dp[z][x-1][y]][s[1][x-1]-'a']+1, dp[z][x][y]);
                        if (y > 0)
                            dp[z][x][y] = min(nxt_occ[dp[z][x][y-1]][s[2][y-1]-'a']+1, dp[z][x][y]);
                    } else if (ind == 1 && x <= m[0] && y <= m[2]) {
                        dp[x][z][y] = nxt_occ[dp[x][z-1][y]][s[1].back()-'a']+1;
                        if (x > 0)
                            dp[x][z][y] = min(nxt_occ[dp[x-1][z][y]][s[0][x-1]-'a']+1, dp[x][z][y]);
                        if (y > 0)
                            dp[x][z][y] = min(nxt_occ[dp[x][z][y-1]][s[2][y-1]-'a']+1, dp[x][z][y]);
                    } else if (ind == 2 && x <= m[0] && y <= m[1]) {
                        dp[x][y][z] = nxt_occ[dp[x][y][z-1]][s[2].back()-'a']+1;
                        if (x > 0)
                            dp[x][y][z] = min(nxt_occ[dp[x-1][y][z]][s[0][x-1]-'a']+1, dp[x][y][z]);
                        if (y > 0)
                            dp[x][y][z] = min(nxt_occ[dp[x][y-1][z]][s[1][y-1]-'a']+1, dp[x][y][z]);
                    }
                }
            }
        } else {
            --m[ind];
            s[ind].pop_back();
        }
        if (dp[m[0]][m[1]][m[2]] <= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}