#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    i64 n, b;
    cin >> n >> b;
    vector<pair<i64, int>> ps;
    for (int i = 2; 1LL * i * i <= b; ++i) {
        if (b % i == 0) {
            ps.emplace_back(i, 0);
            while (b % i == 0) {
                b /= i;
                ++ps.back().second;
            }
        }
    }
    if (b > 1) {
        ps.emplace_back(b, 1);
    }
    i64 res = 2e18;
    for (auto [p, a] : ps) {
        i64 kp = 0;
        for (i64 cur_pow = p; cur_pow <= n; cur_pow *= p) {
            kp += n / cur_pow;
            if ((double)cur_pow * p > n) break;
        }
        res = min(res, kp / a);
    }
    cout << res << "\n";


    return 0;
}