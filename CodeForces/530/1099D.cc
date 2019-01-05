#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, int h, int cur_s, const vector<vector<int>> &g, 
         const vector<int> &s, vector<int> &a) {
    if (s[u] != -1 && cur_s > s[u]) {
        return false;
    }
    if (s[u] == -1) {
        int mn_s = 1'000'000'000;
        for (int v : g[u]) {
            mn_s = min(mn_s, s[v] - cur_s);
        }
        if (g[u].empty()) mn_s = 0;
        if (mn_s < 0) return false;
        a[u] = mn_s;
    } else {
        a[u] = s[u] - cur_s;
    }
    cur_s += a[u];
    for (int v : g[u]) {
        if (!dfs(v, h + 1, cur_s, g, s, a)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i + 1);
    }
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<int> a(n, 0);
    if (!dfs(0, 1, 0, g, s, a)) {
        cout << -1 << "\n";
    } else {
        cout << accumulate(begin(a), end(a), 0LL) << "\n";
    }


    return 0;
}