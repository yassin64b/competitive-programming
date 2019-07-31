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
    int Q;
    cin >> Q;
    vector<vector<pair<int, int>>> b(n);
    vector<int> c(Q, 0);
    for (int q = 0; q < Q; ++q) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x; // a[p-1] = x
            b[p - 1].emplace_back(q, x);
        } else {
            assert(type == 2);
            int x;
            cin >> x; // < x get paid to have x
            c[q] = x;
        }
    }
    for (int i = Q - 2; i >= 0; --i) {
        c[i] = max(c[i], c[i + 1]);
    }
    c.push_back(0);
    
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        int q = -1, x = a[i];
        if (!b[i].empty()) {
            q = b[i].back().first;
            x = b[i].back().second;
        }
        d[i] = max(x, c[q + 1]);
    }
    for (int x : d) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}