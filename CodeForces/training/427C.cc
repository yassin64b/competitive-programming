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

constexpr int MOD = 1000*1000*1000 + 7;
constexpr int MAX = 1000*1000*1000;

class C427 {
private:
    void dfs(int u, const vector<vector<int>> &g, stack<int> &S, vector<int> &vis) {
        vis[u] = 1;
        for (int i = 0; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            if (!vis[v]) {
                dfs(v, g, S, vis);
            }
        }
        S.push(u);
    }
    void dfsSCC(int u, const vector<vector<int>> &g, vector<int> &vis, vector<int> &comp) {
        vis[u] = 1;
        comp.push_back(u);
        
        for (int i = 0; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            if (!vis[v]) {
                dfsSCC(v, g, vis, comp);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n;
        vector<int> cost(n);
        for (int i = 0; i < n; ++i) {
            in >> cost[i];
        }
        in >> m;
        vector<vector<int>> g(n), trans_g(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            in >> u >> v;
            g[u-1].push_back(v-1);
            trans_g[v-1].push_back(u-1);
        }
        
        stack<int> S;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, g, S, vis);
            }
        }
        
        vector<vector<int>> comps;
        vis.assign(n, 0);
        while (!S.empty()) {
            int u = S.top();
            S.pop();
            if (!vis[u]) {
                vector<int> comp;
                //cout << "SCC: ";
                dfsSCC(u, trans_g, vis, comp);
                //cout << endl;
                comps.push_back(comp);
            }
        }
        
        long long numways = 1, money = 0;
        for (int i = 0; i < (int)comps.size(); ++i) {
            int mn = MAX+1, cnt = 0;
            for (int j = 0; j < (int)comps[i].size(); ++j) {
                if (cost[comps[i][j]] < mn) {
                    mn = cost[comps[i][j]];
                    cnt = 1;
                } else if (cost[comps[i][j]] == mn){
                    ++cnt;
                }
            }
            assert(cnt > 0);
            numways = (numways * cnt) % MOD;
            money += mn;
        }
        
        out << money << " " << numways << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    C427 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
