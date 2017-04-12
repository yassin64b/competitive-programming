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

class D472 {
private:
    void dfs(int u, const vector<vector<pair<int, int>>>& g, vector<int>& dist) {
        for (const auto& p : g[u]) {
            int v = p.first, cost = p.second;
            if (dist[v] == -1) {
                dist[v] = dist[u] + cost;
                dfs(v, g, dist);
                //cout << u << " " << v << " " << cost << endl;
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> d(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                in >> d[i][j];
                if ((d[i][j] == 0 && i != j) || (i == j && d[i][j])) {
                    out << "NO\n";
                    return;
                }
            }
        }
        
        vector<vector<pair<int, int>>> mst(n);
        vector<int> taken(n, 0);
        priority_queue<tuple<int, int, int>> pq;
        int mst_cost = 0;
        pq.emplace(0, 0, -1);
        while (!pq.empty()) {
            int u, cost, from;
            tie(cost, u, from) = pq.top();
            pq.pop();
            if (taken[u]) {
                continue;
            }
            if (from >= 0) {
                mst[from].emplace_back(u, -cost);
                mst[u].emplace_back(from, -cost);
            }
            taken[u] = 1;
            mst_cost += -cost;
            for (int v = 0; v < n; ++v) {
                if (!taken[v]) {
                    pq.emplace(-d[u][v], v, u);
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, -1);
            dist[i] = 0;
            dfs(i, mst, dist);
            for (int j = 0; j < n; ++j) {
                if (dist[j] != d[i][j]) {
                    //cout << i << " " << j << " " << dist[j] << endl;
                    out << "NO\n";
                    return;
                }
            }
        }
        out << "YES\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    D472 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
