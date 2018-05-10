#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    int n;
    void dfs(int u, int p, const vector<vector<int>> &g, vector<vector<int>> &up) {
        up[u][0] = p;
        for (int i = 1; (1 << i) <= n; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u, g, up);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int k;
        in >> n >> k;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            in >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        const int root = n - 1;
        int l = 0;
        for (; (1 << l) <= n; ++l);
        --l;
        vector<vector<int>> up(n, vector<int>(l + 1));
        dfs(root, root, g, up);
        vector<int> take(n, 0);
        take[root] = 1;
        int keep = n - k - 1;
        for (int u = n - 2; u >= 0; --u) {
            if (take[u]) continue;
            int v = u, dist = 0;
            for (int i = l; i >= 0; --i) {
                if (!take[up[v][i]]) {
                    v = up[v][i];
                    dist += (1 << i);
                }
            }
            if (dist + 1 <= keep) {
                keep -= dist + 1;
                v = u;
                while (!take[v]) {
                    take[v] = 1;
                    v = up[v][0];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!take[i]) {
                out << i + 1 << " ";
            }
        }
        out << "\n";
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
