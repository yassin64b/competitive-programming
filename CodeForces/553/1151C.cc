#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int MOD = 1'000'000'007;

int f(i64 x) {
    if (x == 0) return 0;
    int mx_pow = 0;
    while ((1LL << mx_pow) <= x) {
        ++mx_pow;
    }
    int odd, even;
    if (mx_pow % 2 == 1) {
        odd = mx_pow;
        even = mx_pow - 1;
    } else {
        even = mx_pow;
        odd = mx_pow - 1;
    }
    even = max(0, even);
    odd = max(0, odd);
    i64 cnt_even = 0;
    i64 cnt_odd = 0;
    for (int cur = 0; cur <= odd; cur += 2) {
        cnt_odd += (1LL << cur);
    }
    for (int cur = 1; cur <= even; cur += 2) {
        cnt_even += (1LL << cur);
    }
    if (even >= odd) {
        cnt_even = x - cnt_odd;
    } else {
        cnt_odd = x - cnt_even;
    }
    cnt_even %= MOD;
    cnt_odd %= MOD;

    return ((i64)cnt_even * (cnt_even + 1) % MOD + 
            (i64)cnt_odd * cnt_odd % MOD) % MOD;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    i64 l, r;
    cin >> l >> r;

    cout << ((f(r) - f(l - 1)) % MOD + MOD) % MOD << "\n";


    return 0;
}