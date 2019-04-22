#include <bits/stdc++.h>

using namespace std;

int query(const vector<int> &a, const vector<int> &b) {
    cout << a.size() << " " << b.size() << " ";
    for (int x : a) cout << x << " ";
    for (int x : b) cout << x << " ";
    cout << endl;
    int dist;
    cin >> dist;
    if (dist == -1) exit(0);
    return dist;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<pair<int, int>> a, b;
        a.emplace_back(1, n);
        int mx = 0;
        for (int i = 0; i < 9; ++i) {
            vector<pair<int, int>> na, nb;
            for (const auto &[l, r] : a) {
                if (l == r) {
                    na.emplace_back(l, r);
                } else {
                    int mid = (l + r) / 2;
                    assert(l <= mid);
                    assert(mid + 1 <= r);
                    
                    na.emplace_back(l, mid);
                    nb.emplace_back(mid + 1, r);
                }
            }
            for (const auto &[l, r] : b) {
                if (l == r) {
                    nb.emplace_back(l, r);
                } else {
                    int mid = (l + r) / 2;
                    assert(l <= mid);
                    assert(mid + 1 <= r);
                    na.emplace_back(l, mid);
                    nb.emplace_back(mid + 1, r);
                }
            }
            a = na;
            b = nb;
            vector<int> qa, qb;
            for (const auto &[l, r] : a) {
                for (int j = l; j <= r; ++j) qa.push_back(j);
            }
            for (const auto &[l, r] : b) {
                for (int j = l; j <= r; ++j) qb.push_back(j);
            }
            mx = max(mx, query(qa, qb));
        }
        cout << -1 << " " << mx << endl;
    }
    return 0;
}