#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<i64> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int q;
    cin >> q;
    vector<pair<i64, int>> ri(q);
    for (int i = 0; i < q; ++i) {
        i64 l, r;
        cin >> l >> r;
        r -= l;
        ri[i] = {r, i};
    }
    sort(begin(ri), end(ri));
    sort(begin(s), end(s));
    priority_queue<i64> dist;
    for (int i = 0; i + 1 < n; ++i) {
        dist.push(-(s[i + 1] - s[i]));
    }
    vector<i64> res(q, 0);
    i64 cur = 0;
    for (int i = 0; i < q; ++i) {
        auto [r, ind] = ri[i];
        while (!dist.empty() && -dist.top() <= r) {
            cur += -dist.top();
            dist.pop();
        }
        res[ind] = cur + (((i64)dist.size() + 1) * (r + 1));
    }
    for (i64 x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}