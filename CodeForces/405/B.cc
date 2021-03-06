/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <fstream>

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <queue>
#include <functional>
#include <stack>
#include <cassert>

using namespace std;

class TaskB {
private:
    pair<int,int> dfs(int u, const vector<vector<int>> &g, vector<int> &vis) {
        vis[u] = 1;
        pair<int,int> ret{1, (int)g[u].size()};
        for (int i = 0; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            if (!vis[v]) {
                pair<int,int> tmp = dfs(v, g, vis);
                ret.first += tmp.first;
                ret.second += tmp.second;
            }
        }
        return ret;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        
        vector<vector<int>> g(n);
        vector<pair<int,int>> edg(m);
        for (int i = 0; i < m; ++i) {
            in >> edg[i].first >> edg[i].second;
            --edg[i].first; --edg[i].second;
            
            g[edg[i].first].push_back(edg[i].second);
            g[edg[i].second].push_back(edg[i].first);
        }
        
        vector<int> vis(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                pair<int,int> ret = dfs(i, g, vis);
                //cout << i << " " << ret.first << " " << ret.second << endl;
                if (ret.second != ret.first * ((long long)ret.first-1)) {
                    out << "NO\n";
                    return;
                }
            }
        }
        out << "YES\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
