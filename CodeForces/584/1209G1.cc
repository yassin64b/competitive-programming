#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    constexpr int MXV = 200'000;
    vector<int> mn(MXV + 1, MXV + 1), mx(MXV + 1, -1), cnt(MXV + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn[a[i]] = min(mn[a[i]], i);
        mx[a[i]] = max(mx[a[i]], i);
        ++cnt[a[i]];
    }
    int res = 0;
    for (int i = 0, cur_end = 0, cur_start = 0, cur_mx_cnt = 0; i < n; ++i) {
        cur_end = max(cur_end, mx[a[i]]);
        cur_mx_cnt = max(cur_mx_cnt, cnt[a[i]]);
        if (cur_end == i) {
            res += cur_end - cur_start + 1 - cur_mx_cnt;
            cur_start = i + 1;
            cur_mx_cnt = 0;
        }
    }
    cout << res << "\n";

    return 0;
}