#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s;
    int n;
    cin >> s >> n;
    vector<int> res_val(10, 0), res_pow(10, 10);
    for (int i = 0; i < 10; ++i) {
        res_val[i] = i;
    }
    constexpr int MOD = 1'000'000'007;
    vector<pair<int, string>> q;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        int d = tmp[0] - '0';
        string t = tmp.substr(3);
        q.emplace_back(d, t);
    }
    for (int i = n - 1; i >= 0; --i) {
        int new_val = 0, new_pow = 1;
        auto [d, t] = q[i];
        for (int j = 0; j < (int)t.size(); ++j) {
            int cur = t[j] - '0';
            new_val = (1LL * new_val * res_pow[cur] + res_val[cur]) % MOD;
            new_pow = (1LL * new_pow * res_pow[cur]) % MOD;
        }
        res_pow[d] = new_pow;
        res_val[d] = new_val;
    }
    int res = 0;
    for (char c : s) {
        res = (1LL * res * res_pow[c - '0'] + res_val[c - '0']) % MOD;
    }
    cout << res << "\n";

    return 0;
}