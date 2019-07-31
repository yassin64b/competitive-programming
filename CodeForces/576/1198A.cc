#include <bits/stdc++.h>

using namespace std;

long long cost(int n, int dis_n, pair<int, int> p) {
    int lg = 0;
    while ((1 << lg) < dis_n) ++lg;
    return 1LL * n * lg;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, I;
    cin >> n >> I;
    int m = 8 * I;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int res = n;
    
    vector<pair<int, int>> b;
    for (const auto &p : cnt) {
        b.push_back(p);
    }
    sort(begin(b), end(b));
    int nb = b.size();
    int cur_cnt = 0;
    for (int i = 0, j = 0; i < nb; ++i) {
        assert(j >= i);
        while (j < nb && cost(n, j - i + 1, b[j]) <= m) {
            cur_cnt += b[j].second;
            res = min(res, n - cur_cnt);
            ++j;
        }
        cur_cnt -= b[i].second;
    }
    cout << res << "\n";

    return 0;
}