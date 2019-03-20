#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> pref(a);
    for (int i = 1; i < n; ++i) {
        pref[i] ^= pref[i - 1];
    }

    constexpr int MX = (1 << 20);
    vector<vector<int>> cnt(2, vector<int>(MX, 0));
    cnt[1][0] = 1;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += cnt[i % 2][pref[i]];
        ++cnt[i % 2][pref[i]];
    }
    cout << res << "\n";


    return 0;
}