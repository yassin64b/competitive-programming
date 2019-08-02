#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 998244353;

int solve(int a, int b, vector<vector<int>> &dp, const vector<int> &c) {
    const int n = c.size();
    if (a >= b) return 1;
    int &res = dp[a][b];
    if (res != -1) {
        return res;
    }
    res = 0;
    int mn = n + 1, ind = -1;
    for (int i = a; i <= b; ++i) {
        if (c[i] < mn) {
            mn = c[i];
            ind = i;
        }
        int x1 = solve(a, ind - 1, dp, c);
        int x2 = solve(ind + 1, i, dp, c);
        int y = solve(i + 1, b, dp, c);
        res = (res + 1LL * x1 * x2 % MOD * y) % MOD;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    vector<vector<int>> dp(m, vector<int>(m, -1));
    int res = solve(0, m - 1, dp, c);
    cout << res << "\n";

    return 0;
}