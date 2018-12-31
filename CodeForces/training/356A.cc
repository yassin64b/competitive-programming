#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    set<int> knights;
    for (int i = 1; i <= n; ++i) {
        knights.insert(i);
    }
    vector<int> beat_by(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        auto it = knights.lower_bound(l);
        while (it != end(knights) && *it <= r) {
            if (*it != x) {
                beat_by[*it] = x;
                it = knights.erase(it);
            } else {
                ++it;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << beat_by[i] << " ";
    }
    cout << "\n";

    return 0;
}