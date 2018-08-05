#include <bits/stdc++.h>

using namespace std;

class TaskD {
private:
    void dfs(int u, const vector<pair<int, vector<int>>> &g, vector<bool> &val,
            vector<bool> &change)
    {
        for (int v : g[u].second) {
            dfs(v, g, val, change);
        }
        if (g[u].first == 4) {
            int a = g[u].second[0];
            change[a] = 1;
            val[u] = !val[a];
        } else if (g[u].first <= 3) {
            int a = g[u].second[0], b = g[u].second[1];
            if (g[u].first == 1) {
                val[u] = (val[a] && val[b]);
                if (val[u]) {
                    change[a] = change[b] = 1;
                } else if (val[a] && !val[b]) {
                    change[b] = 1;
                } else if (!val[a] && val[b]) {
                    change[a] = 1;
                }
            } else if (g[u].first == 2) {
                val[u] = (val[a] || val[b]);
                if (!val[u]) {
                    change[a] = change[b] = 1;
                } else if (val[a] && !val[b]) {
                    change[a] = 1;
                } else if (!val[a] && val[b]) {
                    change[b] = 1;
                }
            } else {
                val[u] = (val[a] ^ val[b]);
                change[a] = change[b] = 1;
            }
        }
    }
    void dfs2(int u, bool cur, const vector<pair<int, vector<int>>> &g,
              vector<bool> &res, vector<bool> &change)
    {
        cur = cur && change[u];
        for (int v : g[u].second) {
            dfs2(v, cur, g, res, change);
        }
        if (g[u].first == 5) {
            if (cur) {
                res[u] = !res[0];
            } else {
                res[u] = res[0];
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<pair<int, vector<int>>> g(n);
        vector<bool> val(n, 0), change(n, 0);
        change[0] = 1;
        for (int i = 0, a, b; i < n; ++i) {
            string s;
            in >> s;
            if (s == "NOT") {
                g[i].first = 4;
                in >> a;
                g[i].second.push_back(a - 1);
            } else if (s == "IN") {
                g[i].first = 5;
                int x;
                in >> x;
                val[i] = x;
            } else {
                if (s == "AND") {
                    g[i].first = 1;
                } else if (s == "OR") {
                    g[i].first = 2;
                } else if (s == "XOR") {
                    g[i].first = 3;
                }
                in >> a >> b;
                g[i].second.push_back(a - 1);
                g[i].second.push_back(b - 1);
            }
        }
        dfs(0, g, val, change);
        dfs2(0, 1, g, val, change);
        for (int u = 0; u < n; ++u) {
            if (g[u].first == 5) {
                out << val[u];
            }
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
