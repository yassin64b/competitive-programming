#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

void dfs(int u, vector<vector<int>> &g, vector<int> &belong, int r) 
{
    belong[u] = r;
    for (int &v : g[u]) {
        if (belong[v] == -1) {
            dfs(v, g, belong, r);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        --c[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    vector<int> belong(n, -1);
    for (int i = 0; i < k; ++i) {
        dfs(c[i], g, belong, c[i]);
    }

    vector<int> cnt(n, 0);
    int cntfree = 0;
    for (int i = 0; i < n; ++i) {
        if (belong[i] != -1) {
            ++cnt[belong[i]];
        } else {
            ++cntfree;
        }
    }

    vector<int> ifree(n, 0);
    for (int i = 0; i < n; ++i) {
        if (belong[i] != -1) {
            ifree[belong[i]] += cnt[belong[i]] - g[i].size() - 1;
        }
    }

    int res = 0;

    for (int i = 0; i < k; ++i) {
        int tmp = (cntfree * cnt[c[i]]);

        if (tmp > res) {
            res = tmp;
        }
    }

    for (int i = 0; i < k; ++i) {
        res += ifree[c[i]]/2;
    }

    int iadd = 0;
    for (int u = 0; u < n; ++u) {
        if (belong[u] == -1) {
            int tmp = 0;
            for (int &v : g[u]) {
                if (belong[v] == -1) {
                    ++tmp;
                }
            }
            iadd += cntfree - tmp - 1;
        }
    }

    cout << res + iadd/2 << endl;

    return 0;
}