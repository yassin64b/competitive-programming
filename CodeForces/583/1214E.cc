#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> d(n);
    vector<vector<int>> dist(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        dist[d[i]].push_back(i);
    }
    vector<pair<int, int>> e;
    int last = -1;
    vector<int> path;
    vector<int> pos(n, -1);
    for (int i = n; i >= 1; --i) {
        for (int u : dist[i]) {
            if (last != -1) {
                e.emplace_back(last, 2 * u);
            }
            pos[u] = path.size();
            path.push_back(2 * u);
            last = 2 * u;
        }
    }
    for (int i = 0; i < n; ++i) {
        int a = path[i];
        int b = a + 1;

        int j = i + d[a / 2] - 1;
        int c = path[j];

        e.emplace_back(c, b);

        if (j == (int)path.size() - 1) {
            path.push_back(b);
        }
    }
    for (const auto [u, v] : e) {
        cout << u+1 << " " << v+1 << "\n";
    }

    return 0;
}