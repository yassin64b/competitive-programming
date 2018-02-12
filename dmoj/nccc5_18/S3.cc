#include <bits/stdc++.h>

using namespace std;

class nccc5j5s3 {
private:
    bool dfs(int u, int goal, const vector<set<int>> &g, vector<int> &vis) {
        if (u == goal) {
            return true;
        }
        vis[u] = 1;
        for (int v : g[u]) {
            if (!vis[v]) {
                if (dfs(v, goal, g, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    void solve(istream& in, ostream& out) {
        int N, M;
        in >> N >> M;
        vector<set<int>> g(N);
        vector<pair<int, int>> edge(M);
        for (int i = 0; i < M; ++i) {
            int s, t;
            in >> s >> t;
            g[s - 1].insert(t - 1);
            edge[i] = {s - 1, t - 1};
        }
        for (int i = 0; i < M; ++i) {
            int s = edge[i].first, t = edge[i].second;
            g[s].erase(t);
            vector<int> vis(N, 0);
            out << (dfs(0, N - 1, g, vis) ? "YES" : "NO") << "\n";
            g[s].insert(t);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    nccc5j5s3 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
