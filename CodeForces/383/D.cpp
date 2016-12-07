#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void dfs(int i, vector<vector<int>> &g, vector<int> &col, map<int, int> &m, int key)
{
    col[i] = 1;
    m[i] = key;
    for (size_t j = 0; j < g[i].size(); ++j) {
        if (col[g[i][j]] == 0) {
            dfs(g[i][j], g, col, m, key);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, W;
    cin >> n >> m >> W;
    vector<int> w(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    map<int, int> map;
    vector<int> col(n, 0);
    int key = 1;
    for (int i = 0; i < n; ++i) {
        if (col[i] == 0) {
            map[i] = key;
            dfs(i, g, col, map, key);
            ++key;
        }
    }

    vector<int> dp(W+1, 0);
    for (int i = 0; i < n; ++i) {
        vector<int> items;
        int sumw = 0, sumb = 0, ckey = map[i];
        if (map[i] == -1) continue;
        for (int j = 0; j < n; ++j) {
            if (ckey == map[j]) {
                items.push_back(j);
                sumw += w[j];
                sumb += b[j];
                //cout << j << " ";
                map[j] = -1;
            }
        }
        //cout << endl;
        vector<int> dpc(dp);
        for (size_t j = 0; j < items.size(); ++j) {
            for (int k = w[items[j]]; k <= W; ++k) {
                dp[k] = max(dp[k], dpc[k - w[items[j]]] + b[items[j]]);
            }
        } 
        for (int j = sumw; j <= W; ++j) {
            dp[j] = max(dp[j], dpc[j - sumw] + sumb);
        }
    }

    cout << dp[W] << endl;

    return 0;
}