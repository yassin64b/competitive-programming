#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    for (int u = 0; u < n; ++u) {
        if (g[u].size() == 2U) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}