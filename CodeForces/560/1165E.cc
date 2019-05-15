#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(begin(b), end(b));
    constexpr int MOD = 998'244'353;

    vector<long long> ac(n);
    for (int i = 0; i < n; ++i) {
        // contribution of a[i] to the sum
        ac[i] = (long long)a[i] * (i + 1) * (n - i);
    }
    sort(begin(ac), end(ac));
    reverse(begin(ac), end(ac));
    
    // match largest ac[i] with smallest b[i]
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = (res + (long long)(ac[i] % MOD) * b[i]) % MOD;
    }
    cout << res << "\n";

    return 0;
}