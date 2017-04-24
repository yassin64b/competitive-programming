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

constexpr long long LINF = 1000LL * 1000 * 1000 * 1000 * 1000 * 10;
class CLQUED {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, K, X, M, S;
            in >> N >> K >> X >> M >> S;
            --S;
            vector<vector<pair<int, int>>> g(N);
            for (int i = 0; i < M; ++i) {
                int a, b, c;
                in >> a >> b >> c;
                g[a-1].emplace_back(b-1, c);
                g[b-1].emplace_back(a-1, c);
            }
            
            vector<long long> dist(N, LINF);
            priority_queue<pair<long long, int>> pq;
            pq.emplace(-0, S);
            dist[S] = 0;
            while (!pq.empty()) {
                long long cur_cost = -pq.top().first;
                int u = pq.top().second;
                pq.pop();
                if (cur_cost > dist[u]) {
                    continue;
                }
                /*for (int i = 0; u < K && i < K; ++i) { //TLE
                    if (i != u) {
                        if (cur_cost + X < dist[i]) {
                            dist[i] = cur_cost + X;
                            pq.emplace(-dist[i], i);
                        }
                    }
                }*/
                for (int i = 0; i < (int)g[u].size(); ++i) {
                    int v = g[u][i].first, c = g[u][i].second;
                    if (cur_cost + c < dist[v]) {
                        dist[v] = cur_cost + c;
                        pq.emplace(-dist[v], v);
                    }
                }
            }
            
            //relax old cities and rerun Dijkstra --> AC
            long long mn_cost_to_K = LINF;
            for (int i = 0; i < K; ++i) {
                mn_cost_to_K = min(mn_cost_to_K, dist[i]);
            }
            for (int i = 0; i < K; ++i) {
                dist[i] = min(dist[i], mn_cost_to_K + X);
                pq.emplace(-dist[i], i);
            }
            
            while (!pq.empty()) {
                long long cur_cost = -pq.top().first;
                int u = pq.top().second;
                pq.pop();
                if (cur_cost > dist[u]) {
                    continue;
                }
                
                for (int i = 0; i < (int)g[u].size(); ++i) {
                    int v = g[u][i].first, c = g[u][i].second;
                    if (cur_cost + c < dist[v]) {
                        dist[v] = cur_cost + c;
                        pq.emplace(-dist[v], v);
                    }
                }
            }
            
            for (int i = 0; i < N; ++i) {
                out << dist[i] << " ";
            }
            out << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    CLQUED solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}