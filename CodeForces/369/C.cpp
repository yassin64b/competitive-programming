#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

constexpr int64_t INF = 1e18;
int main()
{
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int64_t> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  vector<vector<int64_t>> p(n, vector<int64_t>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> p[i][j];
    }
  }
  
  int last = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (c[i] > 0 && c[i] != last) {
      ++cnt;
      last = c[i];
    }
  }
  if (cnt > k) {
    cout << -1 << endl;
    return 0;
  }

  vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(k+1, vector<int64_t>(m+1, INF)));
  for (int f = 1; f <= m; ++f) {
    if (c[0] != 0) {
      dp[0][1][c[0]] = 0;  
    } else {
      dp[0][1][f] = p[0][f-1];
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (c[i] != 0) {
        dp[i][j][c[i]] = dp[i-1][j][c[i]];
        for (int f = 1; f <= m; ++f) {
          if (f == c[i]) continue;
          dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j-1][f]);
        }
        continue;
      }
      for (int f = 1; f <= m; ++f) {
        dp[i][j][f] = min(dp[i][j][f], dp[i-1][j][f] + p[i][f-1]);
        for (int ff = 1; ff <= m; ++ff) {
          if (f == ff) continue;
          dp[i][j][f] = min(dp[i][j][f], dp[i-1][j-1][ff] + p[i][f-1]);
        }
      }
    }
  }
  
  int64_t ans = INF;
  for (int f = 1; f <= m; ++f) {
    ans = min(ans, dp[n-1][k][f]);
    //cout << dp[n-1][k][f] << endl;
  }
  cout << ((ans == INF) ? -1 : ans) << endl;

  return 0;
}
