#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

constexpr int64_t MINF = -1e18;

//first return value is sum of whole subtree
//second return value is maximum sum in subtree
pair<int64_t, int64_t> dfs(int i, vector<vector<int>> &g, vector<int> &vis, vector<int> &a, int64_t &ans) 
{
    int64_t mx1 = MINF, mx2 = MINF, sum = a[i], res = MINF;
    vis[i] = 1;

    for (size_t j = 0; j < g[i].size(); ++j) {
        if (!vis[g[i][j]]) {
            pair<int64_t, int64_t> tmp = dfs(g[i][j], g, vis, a, ans);
            
            sum += tmp.first;

            int64_t val = tmp.second;
            res = max(res, val);

            if (tmp.second > mx1) {
                mx2 = mx1;
                mx1 = tmp.second;
            } else if (tmp.second > mx2) {
                mx2 = tmp.second;
            }                    
        }
    }
    
    if (mx2 > MINF) ans = max(ans, mx1 + mx2);
    res = max(res, sum);

    return {sum, res};
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
        
    }   

    vector<int> vis(n, 0);
    int64_t ans = MINF;
    (void)dfs(0, g, vis, a, ans);

    if (ans != MINF) {
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}