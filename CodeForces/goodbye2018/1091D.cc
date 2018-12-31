#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    constexpr int MOD = 998244353;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
    vector<int> fac(n + 1, 0);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    }

    int res = (1LL * n * fac[n]) % MOD;
    for (int i = n - 1, cur = 1; i >= 1; --i) {
        cur = (1LL * cur * (i + 1)) % MOD;
        res = (res - cur + MOD) % MOD;
    }
    cout << res << "\n";

    /*// brute force
    vector<int> p;
    do {
        for (int x : v) p.push_back(x);
    } while (next_permutation(begin(v), end(v)));

    int res = 0;
    for (int i = 0, j = 0, sum = 0; i + n <= (int)p.size(); ++i) {
        while (j < (int)p.size() && j < i + n) {
            sum += p[j++];
        }
        res += (sum == n * (n + 1) / 2);
        sum -= p[i];
    }
    cout << res << endl;*/

    return 0;
}