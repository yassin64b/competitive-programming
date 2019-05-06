#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 998'244'353;

int modPow(int a, int b = MOD - 2, int c = MOD) {
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b /= 2;
    }
    return x % c;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int j = n - 1; j >= 0; --j) {
        int sum = 0, inv = modPow(n - j);
        for (int i = n; i >= 0; --i) {
            dp[j][i] = (max(0, (cnt[i] - 1)) + sum) % MOD;
            dp[j][i] = (1LL * dp[j][i] * inv) % MOD;
            sum = (sum + 1LL * cnt[i] * dp[j + 1][i]) % MOD;
        }
    }
    cout << dp[0][0] << "\n";


    return 0;
}