#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    map<int, int> m1, m2;
    map<pair<int, int>, int> m3;
    for (int i = 0; i < n; ++i) {
        cin >> ab[i].first >> ab[i].second;
        ++m1[ab[i].first];
        ++m2[ab[i].second];
        ++m3[ab[i]];
    }
    constexpr int MOD = 998244353;
    vector<int> fac(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }

    i64 x1 = 1, x2 = 1, x3 = 1;
    for (auto [k, v] : m1) {
        x1 = x1 * fac[v] % MOD;
    }
    for (auto [k, v] : m2) {
        x2 = x2 * fac[v] % MOD;
    }
    sort(begin(ab), end(ab));
    for (int i = 1; i < n; ++i) {
        if (ab[i].second < ab[i - 1].second) {
            x3 = 0;
        }
    }
    for (auto [k, v] : m3) {
        x3 = x3 * fac[v] % MOD;
    }

    int res = ((fac[n] - x1 - x2 + x3) % MOD + MOD) % MOD;
    cout << res << "\n";


    return 0;
}