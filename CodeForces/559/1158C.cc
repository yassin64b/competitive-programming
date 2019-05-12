#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int j, int mn, int mx, vector<int> &p, vector<int> &nxt, int n) {
    if (nxt[i] != -1) {
        int i1 = i + 1, j1 = min(nxt[i] - 2, j);
        int len1 = j1 - i1 + 1;
        if (i1 <= j1) 
            dfs(i1, j1, mn, mn + len1 - 1, p, nxt, n);
        
        int i2 = max(i + 1, j1 + 1), j2 = j;
        int len2 = j2 - i2 + 1;
        if (i2 <= j2) 
            dfs(i2, j2, mx - len2 + 1, mx, p, nxt, n);

        p[i] = mn + len1;
    } else {
        int i1 = i + 1, j1 = j;
        int len1 = j1 - i1 + 1;
        if (i1 <= j1 && j1 < n) 
            dfs(i1, j1, mn, mn + len1 - 1, p, nxt, n);

        p[i] = mn + len1;
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    constexpr int MX = 500'001;
    vector<int> nxt(MX), res(MX), cnt(MX);
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            cin >> nxt[i];
        }
        dfs(0, n - 1, 1, n, res, nxt, n);

        bool ok = true;
        set<pair<int, int>> s;
        s.emplace(n + 1, n + 1);
        for (int i = n - 1; i >= 0; --i) {
            auto it = s.upper_bound(pair(res[i], 0));
            int ind = it->second;
            if (ind != nxt[i] && nxt[i] != -1) {
                ok = false;
            }
            while (s.begin()->first < res[i]) {
                s.erase(s.begin());
            }
            s.emplace(res[i], i + 1);
        }
        if (ok) {
            for (int i = 0; i < n; ++i) {
                int x = res[i];
                cout << x << " ";
            }
        } else {
            cout << -1;
        }
        cout << "\n";
    }

    return 0;
}