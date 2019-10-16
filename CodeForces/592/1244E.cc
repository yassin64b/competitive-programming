#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    i64 k;
    cin >> k;
    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++m[a[i]];
    }
    i64 diff = (--m.end())->first - m.begin()->first;
    while (k > 0 && m.size() > 1U) {
        auto it_mn = m.begin();
        auto it_mx = --m.end();
        if (k < min(it_mn->second, it_mx->second)) {
            break;
        }
        if (it_mn->second < it_mx->second) {
            auto it_sec = it_mn;
            ++it_sec;
            int dist = it_sec->first - it_mn->first;
            int cnt = it_mn->second;
            if (k >= 1LL * dist * cnt) {
                k -= 1LL * dist * cnt;
            } else {
                dist = k / cnt;
                k = -1;
            }
            it_sec->second += it_mn->second;
            diff -= dist;
            m.erase(it_mn);
        } else {
            auto it_sec = it_mx;
            --it_sec;
            int dist = it_mx->first - it_sec->first;
            int cnt = it_mx->second;
            if (k >= 1LL * dist * cnt) {
                k -= 1LL * dist * cnt;
            } else {
                dist = k / cnt;
                k = -1;
            }
            it_sec->second += it_mx->second;
            diff -= dist;
            m.erase(it_mx);
        }
    }
    cout << diff << "\n";


    return 0;
}