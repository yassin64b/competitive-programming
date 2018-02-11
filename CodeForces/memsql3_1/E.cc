#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    pair<int, int> dfs(int u, const vector<vector<int>> &g, vector<int> &vis) {
        vis[u] = 1;
        int n = 1, m = g[u].size();
        for (int v : g[u]) {
            if (!vis[v]) {
                auto [v_n, v_m] = dfs(v, g, vis);
                n += v_n;
                m += v_m;
            }
        }
        return {n, m};
    }
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<vector<int>> g(2 * N);
        for (int i = 0; i < N; ++i) {
            int u, v;
            in >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            if (u != v) {
                g[v].push_back(u);
            }
        }
        vector<int> vis(2 * N, 0);
        int res = 1;
        constexpr int MOD = 1'000'000'007;
        for (int u = 0; u < 2 * N; ++u) {
            if (!vis[u] && !g[u].empty()) {
                auto [n, m] = dfs(u, g, vis);
                if (m % 2) { // self loop --> one assignment
                    continue;
                }
                assert(m % 2 == 0);
                assert(n > 1);
                m /= 2;
                if (n == m) { // cycle --> 2 assignments
                    res = (res * 2LL) % MOD;
                } else { // tree --> n assignments
                    assert(m == n - 1);
                    res = (1LL * res * n) % MOD;
                }
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
