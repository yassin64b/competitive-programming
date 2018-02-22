#include <bits/stdc++.h>

using namespace std;

class dmopc17c4p2 {
private:
    void dfs(int u, int goal, const vector<vector<int>> &g, vector<int> &vis,
            vector<int> &path)
    {
        vis[u] = 1;
        if (u == goal) {
            path.push_back(u);
            return;
        }
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, goal, g, vis, path);
                if (!path.empty()) {
                    path.push_back(u);
                    return;
                }
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int N, Q;
        in >> N >> Q;
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            in >> v[i];
        }
        vector<vector<int>> g(N);
        for (int i = 0; i < N - 1; ++i) {
            int a, b;
            in >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        for (int q = 0; q < Q; ++q) {
            int t, x, y;
            in >> t >> x >> y;
            vector<int> vis(N, 0), path;
            dfs(x - 1, y - 1, g, vis, path);
            if (t == 1) {
                int sum = 0;
                for (int u : path) {
                    sum += v[u];
                }
                out << (int)(round((double)sum / path.size()) + 0.2) << "\n";
            } else if (t == 2) {
                vector<int> vals;
                for (int u : path) {
                    vals.push_back(v[u]);
                }
                sort(vals.begin(), vals.end());
                int med;
                if (vals.size() % 2 == 1U) {
                    med = vals[vals.size() / 2];
                } else {
                    med = round((vals[vals.size() / 2 - 1] + vals[vals.size() / 2]) / 2.) + 0.2;
                }
                out << med << "\n";
            } else {
                assert(t == 3);
                map<int, int> m;
                int mx_occ = 0, val = -1;
                for (int u : path) {
                    ++m[v[u]];
                    if (m[v[u]] > mx_occ || (m[v[u]] == mx_occ && v[u] < val)) {
                        mx_occ = m[v[u]];
                        val = v[u];
                    }
                }
                assert(val != -1);
                out << val << "\n";
            }
            
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmopc17c4p2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
