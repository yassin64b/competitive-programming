#include <bits/stdc++.h>

using namespace std;

int dx[]{1, -1, 0, 0};
int dy[]{0, 0, 1, -1};

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> s(p);
    for (int i = 0; i < p; ++i) {
        cin >> s[i];
    }
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<vector<int>>> dist(p, vector<vector<int>>(n, vector<int>(m, -1)));
    vector<queue<pair<int, int>>> q(p);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] >= '1' && grid[i][j] <= '9') {
                q[grid[i][j] - '1'].emplace(i, j);
                dist[grid[i][j] - '1'][i][j] = 0;
            }
        }
    }
    bool made_move = true;
    for (int it = 1; made_move; ++it) {
        made_move = false;
        for (int i = 0; i < p; ++i) {
            while (!q[i].empty()) {
                auto [x, y] = q[i].front();
                if (dist[i][x][y] > 1LL * s[i] * it) {
                    break;
                }
                q[i].pop();
                if (grid[x][y] != '.' && grid[x][y] != i + '1') {
                    continue;
                }
                grid[x][y] = i + '1';
                made_move = true;
                for (int j = 0; j < 4; ++j) {
                    int nx = x + dx[j], ny = y + dy[j];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (grid[nx][ny] == '.' && dist[i][nx][ny] == -1) {
                            dist[i][nx][ny] = dist[i][x][y] + 1;
                            q[i].emplace(nx, ny);
                        }
                    }
                }
            }
        }
    }

    vector<int> res(p, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] >= '1' && grid[i][j] <= '9') {
                ++res[grid[i][j] - '1'];
            }
        }
    }
    for (int i = 0; i < p; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}