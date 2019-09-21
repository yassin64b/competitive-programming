#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int n;
        cin >> n;
        vector<int> s(n);
        map<int, int> cnt;
        for (int i = 0; (1 << i) <= 2048; ++i) {
            cnt[(1 << i)] = 0;
        }
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            ++cnt[s[i]];
        }
        for (auto [k, v] : cnt) {
            int am = v / 2;
            if (am > 0 && 2 * k <= 2048) {
                cnt[2 * k] += am;
            }
        }
        if (cnt[2048]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}