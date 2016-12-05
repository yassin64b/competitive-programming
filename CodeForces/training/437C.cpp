#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> v(n), del(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    for (int i = 0; i < n; ++i) {
        for (int p: g[i]) {
            del[i] += v[p];
        }
    }

    int cost = 0;
    for (int i = 0; i < n; ++i) {
        auto tmp = max_element(v.begin(), v.end());
        int ind = tmp - v.begin();
        cost += del[ind];
        //cout << "del: " << ind+1 << endl;
        for (int p: g[ind]) {
            del[p] -= v[ind];
        }
        v[ind] = -2e9;
    }

    cout << cost << endl;
    


    return 0;
}