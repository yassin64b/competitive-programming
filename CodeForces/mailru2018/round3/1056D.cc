#include <bits/stdc++.h>

using namespace std;

class TaskD {
private:
    void dfs(int u, const vector<vector<int>> &g, vector<int> &vis,
            vector<int> &sub, vector<int> &cnt)
    {
        vis[u] = 1;
        sub[u] = 0;
        bool leaf = true;
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, g, vis, sub, cnt);
                sub[u] += sub[v];
                leaf = false;
            }
        }
        if (leaf) sub[u] = 1;
        cnt[sub[u]] += 1;
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> g(n);
        for (int i = 2; i <= n; ++i) {
            int p;
            in >> p;
            g[p - 1].push_back(i - 1);
        }
        vector<int> vis(n, 0), sub(n, 0), cnt(n + 1, 0);
        dfs(0, g, vis, sub, cnt);
        for (int k = 1, i = 1, sum = 0; k <= n; ++k) {
            while (sum < k) {
                sum += cnt[i++];
            }
            out << i - 1 << " ";
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
