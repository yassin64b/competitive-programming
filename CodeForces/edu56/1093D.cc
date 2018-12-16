#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 998244353;

class TaskD {
private:
    int dfs(int u, const vector<vector<int>> &g, vector<int> &vis, vector<int> &even) {
        vis[u] = 1;
        int cur = 1;
        for (int v : g[u]) {
            if (!vis[v]) {
                even[v] = !even[u];
                int tmp = dfs(v, g, vis, even);
                if (!even[u]) cur = (1LL * cur * tmp) % MOD;
                else cur = (1LL * cur * 2 * tmp) % MOD;
            }
            if (even[v] == even[u]) {
                return 0;
            }
        }
        return cur;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int n, m;
            in >> n >> m;
            vector<vector<int>> g(n);
            for (int i = 0; i < m; ++i) {
                int u, v;
                in >> u >> v;
                g[u - 1].push_back(v - 1);
                g[v - 1].push_back(u - 1);
            }
            int res = 1;
            vector<int> vis1(n, 0), vis2(n, 0);
            vector<int> even1(n, 0), even2(n, 0);
            for (int u = 0; u < n; ++u) {
                if (!vis1[u]) {
                    even1[u] = 0;
                    int tmp1 = dfs(u, g, vis1, even1);
                    even2[u] = 1;
                    int tmp2 = dfs(u, g, vis2, even2);
                    res = (1LL * res * (2LL * tmp1 + tmp2)) % MOD;
                }
            }
            cout << endl;
            out << res << "\n";
        }
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
