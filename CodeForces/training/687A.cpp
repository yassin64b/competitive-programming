#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

bool dfs(int i, bool f, vector<vector<int>> &adj, vector<int> &col)
{
    //cout << i << endl;
    col[i] = (f ? 1 : 2);
    for (int j = 0; j < (int)adj[i].size(); ++j) {
        if (col[adj[i][j]] == 0) {
            if (!dfs(adj[i][j], !f, adj, col)) {
                return false;
            }
        } else if (col[adj[i][j]] == col[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> col(n, 0);
    for (int i = 0; i < n; ++i) {
        if (col[i] == 0) {
            bool ok = dfs(i, true, adj, col);
            if (!ok) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        if (col[i] == 1) {
            a.push_back(i+1);
        } else if (col[i] == 2) {
            b.push_back(i+1);
        }
    }
    cout << a.size() << endl;
    for (int i = 0; i < (int)a.size(); ++i) 
        cout << a[i] << " ";
    cout << endl << b.size() << endl;
    for (int i = 0; i < (int)b.size(); ++i) 
        cout << b[i] << " ";

    return 0;
}