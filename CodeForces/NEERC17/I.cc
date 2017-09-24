#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  int n, m, q, p;
  cin >> n >> m >> q >> p;
  vector<string> g(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  vector<vector<long long>> res(n, vector<long long>(m, 0));
  vector<vector<int>> val(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (g[i][j] >= 'A' && g[i][j] <= 'Z') {
        queue<pair<int, int>> qu;
        qu.emplace(i, j);
        val[i][j] = (g[i][j] - 'A' + 1) * q;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vis[i][j] = true;
        while (!qu.empty()) {
          int a = qu.front().first, b = qu.front().second;
          int v = val[a][b];
          qu.pop();
          res[a][b] += v;
          if (v / 2 > 0) {
            for (int k = 0; k < 4; ++k) {
              if (a + dx[k] >= 0 && a + dx[k] < n && b + dy[k] >= 0 && b + dy[k] < m
                  && g[a + dx[k]][b + dy[k]] != '*' && !vis[a + dx[k]][b + dy[k]]) {
                qu.emplace(a + dx[k], b + dy[k]);
                val[a + dx[k]][b + dy[k]] = v / 2;
                vis[a + dx[k]][b + dy[k]] = true;
              }
            }
          }
        }
      }
    }
  }
  int resval = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      //cout << res[i][j] << " ";
      resval += (res[i][j] > p);
    }
    //cout << endl;
  }
  cout << resval << endl;
}
