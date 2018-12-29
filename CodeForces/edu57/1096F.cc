#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
private:
    vector<int> ft;
    int n;
public:
    FenwickTree(int n_) : n(n_) {
        ft.assign(n_ + 1, 0);
    }
    int rsq(int b) {
        int sum = 0;
        for (; b; b -= (b & (-b))) {
            sum += ft[b];
        }
        return sum;
    }
    int rsq(int a, int b) {
        if (a > b) return 0;
        return rsq(b) - rsq(a - 1);
    }
    void update(int a, int v) {
        for ( ; a < (int)ft.size(); a += (a & (-a))) {
            ft[a] += v;
        }
    }
};

// get modular inverse for prime MOD with call modPow(a, MOD - 2, MOD)
int modpow(int a, int b, int c){
    long long x = 1, y = a;
    while (b > 0){
        if (b%2 == 1){
            x = (x*y) % c;
        }
        y = (y*y) % c;
        b /= 2;
    }
    return x % c;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> p(n), used(n + 1, 0);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        cnt += (p[i] == -1);
        if (p[i] != -1) {
            used[p[i]] = 1;
        }
    }
    constexpr int MOD = 998244353;
    int res = 0;
    // count inversions between known elements
    FenwickTree ft(n);
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) {
            int num_inv = ft.rsq(p[i] + 1, n);
            res = (res + num_inv) % MOD;
            ft.update(p[i], 1);
        }
    }

    // expected number of inversions between unknown elements
    res = (res + 1LL * cnt * (cnt - 1) % MOD * modpow(4, MOD - 2, MOD)) % MOD;
    
    vector<int> gt(n + 1, 0);
    gt[n] = !used[n];
    for (int i = n - 1; i >= 1; --i) {
        gt[i] = gt[i + 1] + !used[i];
    }
    // expected number of inversions between known and unknown
    // with known on the right, unknown on the left
    int cur_cnt = 0, cnt_inv = modpow(cnt, MOD - 2, MOD);
    for (int i = 0; i < n; ++i) {
        if (p[i] == -1) {
            ++cur_cnt;
        } else {
            res = (res + 1LL * cur_cnt * gt[p[i]] % MOD * cnt_inv) % MOD;
        }
    }

    // expected number of inversions between known and unknown
    // with known on the left, unknown on the right
    cur_cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (p[i] == -1) {
            ++cur_cnt;
        } else {
            res = (res + 1LL * cur_cnt * (cnt - gt[p[i]]) % MOD * cnt_inv) % MOD;
        }
    }

    cout << res << "\n";

    return 0;
}