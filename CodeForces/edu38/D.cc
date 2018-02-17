#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<vector<pair<int, long long>>> g(n);
        for (int i = 0; i < m; ++i) {
            int v, u;
            long long w;
            in >> v >> u >> w;
            g[v - 1].emplace_back(u - 1, w);
            g[u - 1].emplace_back(v - 1, w);
        }
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        priority_queue<pair<long long, int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(-a[i], i);
        }
        vector<long long> res(n, 0);
        while (!pq.empty()) {
            auto [cur_cost, u] = pq.top();
            cur_cost *= -1;
            pq.pop();
            if (res[u]) {
                continue;
            }
            res[u] = cur_cost;
            for (auto [v, w] : g[u]) {
                if (!res[v]) {
                    pq.emplace(-(cur_cost + 2 * w), v);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            out << res[i] << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
