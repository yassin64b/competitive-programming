#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

vector<int> fac, fac_inv;

int mod_inv(int a) {
    int b = MOD - 2, c = MOD;
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

int num_paths(int x1, int y1, int x2, int y2) {
    if (!(x1 <= x2 && y1 <= y2)) {
        return 0;
    }
    x2 -= x1;
    y2 -= y1;
    // (x2 + y2) choose x2
    return 1LL * fac[x2 + y2] * fac_inv[y2] % MOD * 1LL * fac_inv[x2] % MOD;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> rc(n);
    for (int i = 0; i < n; ++i) {
        cin >> rc[i].first >> rc[i].second;
    }
    sort(begin(rc), end(rc));
    rc.emplace_back(h, w);

    constexpr int MXV = 200'000;
    fac.assign(MXV + 1, 1);
    fac_inv.assign(MXV + 1, 1);
    for (int i = 1; i <= MXV; ++i) {
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    }
    for (int i = 0; i <= MXV; ++i) {
        fac_inv[i] = mod_inv(fac[i]);
    }

    vector<int> dp(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        auto [x1, y1] = rc[i];
        dp[i] = num_paths(1, 1, x1, y1);
        for (int j = 0; j < i; ++j) {
            auto [x2, y2] = rc[j];
            dp[i] = (dp[i] - 1LL * dp[j] * num_paths(x2, y2, x1, y1)) % MOD;
            if (dp[i] < 0) dp[i] += MOD;
        }
    }
    cout << dp[n] << "\n";

    return 0;
}