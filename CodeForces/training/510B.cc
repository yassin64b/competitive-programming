#include <bits/stdc++.h>

using namespace std;

constexpr int NUM_DIR = 4;
int dx[]{1, -1, 0, 0};
int dy[]{0, 0, 1, -1};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs(int x, int y, int px, int py, const vector<string> &board, 
         vector<vector<int>> &vis) {
    const int n = board.size(), m = board[0].size();
    vis[x][y] = 1;
    for (int i = 0; i < NUM_DIR; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if ((nx != px || ny != py) && valid(nx, ny, n, m) && board[nx][ny] == board[x][y]) {
            if (vis[nx][ny]) {
                return true;
            } else {
                if (dfs(nx, ny, x, y, board, vis)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) {
                if (dfs(i, j, -1, -1, board, vis)) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}