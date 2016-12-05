#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

void dfs(int i, vector<vector<bool>> &g, vector<bool> &vis)
{
    vis[i] = true;
    for (int j = 0; j < (int)vis.size(); ++j) {
        if (!vis[j] && g[i][j]) {
            dfs(j, g, vis);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }  
    for (int i = 0; i < n; ++i) {
        if (a[i].size() > 0) break;
        if (i == n-1 && a[i].size() == 0) {
            cout << n << endl;
            return 0;
        }
    }

    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int ii = 0, jj = 0; jj < (int)a[j].size() && ii < (int)a[i].size(); ) {
                if (a[i][ii] > a[j][jj]) {
                    ++jj;
                } else if (a[i][ii] < a[j][jj]) {
                    ++ii;
                } else {
                    g[i][j] = true;
                    break;
                }
            }
        }
    }

    vector<bool> vis(n, false);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ++cnt;
            dfs(i, g, vis);
        }
    }
    cout << cnt-1 << endl;

    return 0;
}