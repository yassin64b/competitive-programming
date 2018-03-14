#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

constexpr int MOD = 1'000'000'007;

int main() 
{
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    int mx_cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        mx_cnt = max(mx_cnt, cnt[a[i]]);
    }
    bool fixed = false;
    int res = 1;
    for (const auto &p : cnt) {
        if (p.second == mx_cnt) {
            if (!fixed) {
                fixed = true;
                continue;
            }
        }
        for (int j = 0; j < p.second; ++j) {
            res = 1LL * res * (mx_cnt - j) % MOD;
        }
    }
    cout << res << "\n";
    
    return 0;
}