#include <bits/stdc++.h>

using namespace std;

class arc092_f {
private:
    void dfs(int u, const vector<vector<int>> &g, vector<int> &vis, int nogo, int id) {
        vis[u] = id;
        for (int v : g[u]) {
            if (!vis[v] && v != nogo) {
                dfs(v, g, vis, nogo, id);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int N, M;
        in >> N >> M;
        vector<int> a(M), b(M);
        vector<vector<int>> g(N);
        for (int i = 0; i < M; ++i) {
            in >> a[i] >> b[i];
            --a[i];
            --b[i];
            g[a[i]].push_back(b[i]);
        }
        vector<vector<int>> reachable(N, vector<int>(N, 0));
        for (int u = 0; u < N; ++u) {
            dfs(u, g, reachable[u], -1, 1);
        }
        vector<vector<int>> reach_from_a(N, vector<int>(N, 0));
        vector<vector<int>> reach_from_b(N, vector<int>(N, 0));
        for (int u = 0; u < N; ++u) {
            sort(begin(g[u]), end(g[u]));
            for (int v : g[u]) {
                if (!reach_from_a[u][v])
                    dfs(v, g, reach_from_a[u], u, v + 1);
            }
            for (int i = (int)g[u].size() - 1; i >= 0; --i) {
                int v = g[u][i];
                if (!reach_from_b[u][v])
                    dfs(v, g, reach_from_b[u], u, v + 1);
            }
        }
        for (int i = 0; i < M; ++i) {
            bool cond1 = reachable[b[i]][a[i]];
            bool cond2 = reach_from_a[a[i]][b[i]] != b[i] + 1
                        || reach_from_b[a[i]][b[i]] != b[i] + 1;
            out << ((cond1 == cond2) ? "same" : "diff") << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc092_f solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
