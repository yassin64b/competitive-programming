#include <bits/stdc++.h>

using namespace std;

void dfs1(int x, int y, int n, int m, vector<string> &g) {
    g[x][y] = '#';
    if (x + 1 < n && g[x + 1][y] == '.') {
        dfs1(x + 1, y, n, m, g);
    }
    if (g[n - 1][m - 1] == '.' && y + 1 < m && g[x][y + 1] == '.') {
        dfs1(x, y + 1, n, m, g);
    }
}
void dfs2(int x, int y, int n, int m, vector<string> &g) {
    g[x][y] = '#';
    if (y + 1 < m && g[x][y + 1] == '.') {
        dfs2(x, y + 1, n, m, g);
    }
    if (g[n - 1][m - 1] == '.' && x + 1 < n && g[x + 1][y] == '.') {
        dfs2(x + 1, y, n, m, g);
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    dfs1(0, 0, n, m, g);
    if (g[n - 1][m - 1] == '.') {
        cout << 0 << "\n";
        return 0;
    }
    g[0][0] = g[n - 1][m - 1] = '.';
    dfs2(0, 0, n, m, g);
    if (g[n - 1][m - 1] == '.') {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }

    return 0;
}