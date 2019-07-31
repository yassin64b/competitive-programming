#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> e;
        vector<vector<int>> g(3 * n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
            e.emplace_back(u - 1, v - 1);
        }
        vector<int> matching;
        vector<int> blocked(3 * n, 0);
        for (int i = 0; i < m; ++i) {
            auto [u, v] = e[i];
            if (!blocked[u] && !blocked[v]) {
                matching.push_back(i);
                blocked[u] = blocked[v] = 1;
            }
        }
        if ((int)matching.size() >= n) {
            cout << "Matching\n";
            for (int i = 0; i < n; ++i) {
                cout << matching[i] + 1 << " ";
            }
            cout << "\n";
        } else {
            cout << "IndSet\n";
            int cnt_is = 0;
            for (int i = 0; cnt_is < n && i < 3 * n; ++i) {
                if (!blocked[i]) {
                    ++cnt_is;
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}