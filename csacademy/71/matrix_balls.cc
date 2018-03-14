#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;

void dfs(int i, int j, const vector<vector<int>> &A, vector<vector<pair<int, int>>> &res,
        vector<vector<int>> &vis, vector<vector<int>> &cnt) 
{
    vis[i][j] = 1;
    int ii = i, jj = j;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (i + di >= 0 && i + di < N && j + dj >= 0 && j + dj < M && A[i + di][j + dj] < A[ii][jj]) {
                ii = i + di;
                jj = j + dj;
            }
        }
    }
    if (ii == i && jj == j) {
        res[i][j] = {i, j};
    } else if (vis[ii][jj]) {
        res[i][j] = res[ii][jj];
    } else {
        dfs(ii, jj, A, res, vis, cnt);
        res[i][j] = res[ii][jj];
    }
    ++cnt[res[i][j].first][res[i][j].second];
}

int main() 
{
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    vector<vector<pair<int, int>>> res(N, vector<pair<int, int>>(M, {-1, -1}));
    vector<vector<int>> vis(N, vector<int>(M, 0));
    vector<vector<int>> cnt(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!vis[i][j]) {
                dfs(i, j, A, res, vis, cnt);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << cnt[i][j] << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}