#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }   
    int m;
    cin >> m;
    int cycle_cnt = 0;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ++cycle_cnt;
            int j = i;
            while (!vis[j]) {
                vis[j] = cycle_cnt;
                j = p[j];
            }
        }
    }
    int num_swaps = n - cycle_cnt;
    vector<pair<int, int>> res;
    {
        int i = 0;
        for (int j = i + 1; num_swaps < m && j < n; ++j) {
            if (vis[i] != vis[j]) {
                res.emplace_back(i + 1, j + 1);
                for (int k = 0, col = vis[j]; k < n; ++k) {
                    if (vis[k] == col) {
                        vis[k] = vis[i];
                    }
                }
                ++num_swaps;
            }
        }
    }
    for (int i = 0; num_swaps > m && i < n; ) {
        int mn = n;
        for (int j = 0; j < n; ++j) {
            if (i != j && vis[j] == vis[i]) {
                mn = min(mn, j);
            }
        }
        if (mn == n) {
            ++i;
            continue;
        }
        swap(p[i], p[mn]);
        --num_swaps;
        res.emplace_back(i + 1, mn + 1);

        vis.assign(n, 0);
        cycle_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++cycle_cnt;
                int j = i;
                while (!vis[j]) {
                    vis[j] = cycle_cnt;
                    j = p[j];
                }
            }
        }
    }
    
    cout << res.size() << "\n";
    for (const auto &[i, j] : res) {
        cout << i << " " << j << " ";
    }
    cout << "\n";

    return 0;
}