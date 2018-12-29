#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s, good;
    int k;
    cin >> s >> good >> k;
    for (char &c : good) {
        c -= '0';
    }

    vector<set<long long>> good_s(1'501);
    int n = s.size();
    constexpr long long base = 41, MOD = 18014398777917439;
    for (int i = 0; i < n; ++i) {
        int cur_bad = 0;
        long long cur_hash = 0;
        for (int j = i; j < n; ++j) {
            cur_bad += !good[s[j] - 'a'];
            if (cur_bad > k) {
                break;
            }
            int cur_len = j - i + 1;
            cur_hash = (1LL * cur_hash * base + 37 * (s[j] - 'a' + 1)) % MOD;
            good_s[cur_len].insert(cur_hash);
        }
    }
    int res = 0;
    for (const auto &gs : good_s) {
        res += gs.size();
    }
    cout << res << "\n";

    return 0;
}