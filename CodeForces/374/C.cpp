#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <utility>
using namespace std;

const int MAXN = 5001;
const int INF = 1e9 + 1;

vector<pair<int,int>> g[MAXN];
int dp[MAXN][MAXN], par[MAXN][MAXN];
char used[MAXN];
int n, m, T;

void dfs(int v)
{
    if(used[v]) return;
    used[v] = 1;
    for(int i = 0; i < (int)g[v].size(); ++i)
        dfs(g[v][i].first);

    for(int i = 0; i < (int)g[v].size(); ++i)
    {
        int to = g[v][i].first, w = g[v][i].second;
        for(int j = 1; j <= n; ++j)
        {
            if(dp[to][j-1] + w < dp[v][j] && dp[to][j-1] + w <= T)
            {
                dp[v][j] = dp[to][j-1] + w;
                par[v][j] = to;
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
   
    cin >> n >> m >> T;

    for(int i = 0; i < m; ++i)
    {
        int u, v, t;
        cin >> u >> v >> t;
        g[v].push_back({u, t});
    }

    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = INF, par[i][j] = -1;

    dp[1][1] = dp[1][0] = 0;
    used[1] = 1;

    dfs(n);

    int ans;
    for(ans = n; ans >= 1; --ans)
        if(dp[n][ans] <= T)
            break;
    cout << ans << endl;

    vector<int> path;
    int cur = n;
    while(ans)
    {
        path.push_back(cur);
        cur = par[cur][ans];
        --ans;
    }
    for(int i = (int)path.size()-1; i >= 0; --i)
        cout << path[i] << " ";
    cout << endl;

	return 0;
}