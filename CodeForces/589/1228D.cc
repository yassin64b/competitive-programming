#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    set<int> v1;
    for (int i = 0; i < n; ++i) v1.insert(i);
    for (int v : g[0]) {
        v1.erase(v);
    }
    set<int> v2;
    for (int i = 0; i < n; ++i) {
        if (v1.count(i) == 0) {
            v2.insert(i);
        }
    }
    if (v2.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    int u = *v2.begin();
    for (int v : g[u]) {
        v2.erase(v);
    }

    set<int> v3;
    for (int i = 0; i < n; ++i) {
        if (v1.count(i) == 0 && v2.count(i) == 0) {
            v3.insert(i);
        }
    }


    bool ok = !(v1.empty() || v2.empty() || v3.empty());
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            if (v1.count(u) && v1.count(v)
                || v2.count(u) && v2.count(v)
                || v3.count(u) && v3.count(v))
                ok = false;
        }
    }
    for (int u = 0; u < n; ++u) {
        int num_out = g[u].size();
        int num_should = 0;
        if (v1.count(u)) {
            num_should = v2.size() + v3.size();
        } else if (v2.count(u)) {
            num_should = v1.size() + v3.size();
        } else {
            num_should = v1.size() + v2.size();
        }
        if (num_should != num_out) 
            ok = false;
    }
    if (!ok) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (v1.count(i)) {
            cout << 1 << " ";
        } else {
            cout << (v2.count(i) ? 2 : 3) << " ";
        }
    }


    return 0;
}