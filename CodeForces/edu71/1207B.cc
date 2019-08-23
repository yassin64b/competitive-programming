#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(a);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> ops;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = m - 2; j >= 0; --j) {
            if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
                ops.emplace_back(i, j);
                b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = 1;
            }
        }
    }
    if (a == b) {
        cout << ops.size() << "\n";
        for (auto [x, y] : ops) {
            cout << x + 1 << " " << y + 1 << "\n";
        }
    } else {
        cout << -1 << "\n";
    }

    return 0;
}