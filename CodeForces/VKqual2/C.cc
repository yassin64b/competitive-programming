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
#include <numeric>
#include <cassert>

using namespace std;

class TaskC {
private:
    void dfs(int u, const vector<vector<int>> &g, vector<int> &vis) {
        vis[u] = 1;
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, g, vis);
            }
        }
    }
    bool dfs(int u, const vector<vector<int>> &g, vector<int> &vis, vector<int> &res, vector<int> &rec) {
        vis[u] = 1;
        rec[u] = 1;
        for (int v : g[u]) {
            if (v != -1 && rec[v]) {
                return false;
            }
            if (v != -1 && !vis[v]) {
                if (!dfs(v, g, vis, res, rec)) {
                    return false;
                }
            }
        }
        res.push_back(u);
        rec[u] = 0;
        
        return true;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> need(k), inv_need(n, 0);
        vector<vector<int>> g(n), trans_g(n);
        for (int i = 0; i < k; ++i) {
            in >> need[i];
            --need[i];
            inv_need[need[i]] = 1;
        }
        for (int i = 0; i < n; ++i) {
            int t;
            in >> t;
            for (int j = 0; j < t; ++j) {
                int v;
                in >> v;
                g[v-1].push_back(i);
                trans_g[i].push_back(v-1);
            }
        }
        vector<int> vis(n, 0), res;
        for (int i = 0; i < k; ++i) {
            if (!vis[need[i]]) {
                dfs(need[i], trans_g, vis);
            }
        }
        
        //remove unneeded courses
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                g[i].clear();
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int &v : g[i]) {
                if (!vis[v]) {
                    v = -1;
                }
            }
        }
        
        vis.assign(n, 0);
        vector<int> rec(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && (g[i].size() > 0 || inv_need[i])) {
                if (!dfs(i, g, vis, res, rec)) {
                    out << -1 << "\n";
                    return;
                }
            }
        }
        out << res.size() << "\n";
        for (int i = (int)res.size()-1; i >= 0; --i) {
            out << res[i]+1 << " ";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
