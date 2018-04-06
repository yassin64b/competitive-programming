#include <bits/stdc++.h>

using namespace std;

class gcj_full_binary_tree {
private:
    void dfs(int u, const vector<vector<int>> &g, vector<int> &vis,
            vector<int> &del, vector<int> &sz)
    {
        vis[u] = 1;
        sz[u] = 1;
        vector<int> children;
        for (int v : g[u]) {
            if (!vis[v]) {
                children.push_back(v);
                dfs(v, g, vis, del, sz);
                sz[u] += sz[v];
            }
        }
        if ((int)children.size() == 1) {
            del[u] = sz[children[0]];
        } else if ((int)children.size() > 2) {
            vector<pair<int, int>> cost;
            for (int v : children) {
                cost.emplace_back(del[v] - sz[v], v);
            }
            // del should be small, sz large for the 2 children kept
            sort(begin(cost), end(cost)); 
            del[u] += del[cost[0].second] + del[cost[1].second]; // keep cost[0], cost[1]
            for (int j = 2; j < (int)cost.size(); ++j) { // delete rest
                del[u] += sz[cost[j].second];
            }
        } else {
            for (int v : children) {
                del[u] += del[v];
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<vector<int>> g(N);
            for (int i = 0; i < N - 1; ++i) {
                int x, y;
                in >> x >> y;
                g[x - 1].push_back(y - 1);
                g[y - 1].push_back(x - 1);
            }
            int ans = N;
            for (int r = 0; r < N; ++r) {
                vector<int> vis(N, 0), del(N, 0), sz(N, 0);
                dfs(r, g, vis, del, sz);
                ans = min(ans, del[r]);
            }
            assert(ans < N);
            out << "Case #" << t << ": " << ans << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_full_binary_tree solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
