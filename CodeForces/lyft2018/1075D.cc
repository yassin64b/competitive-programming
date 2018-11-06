#include <bits/stdc++.h>

using namespace std;

class TaskD {
private:
    int query(char type, int node) {
        cout << type << " " << node + 1 << "\n";
        cout.flush();
        if (type == 'C') {
            return 0;
        }
        int res;
        cin >> res;
        if (res == -1) {
            exit(0);
        }
        return res - 1;
    }
    void dfs(int u, int dest, const vector<vector<int>> &g, vector<int> &vis, vector<int> &path) {
        vis[u] = 1;
        if (u == dest) {
            path.push_back(u);
            return;
        }
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, dest, g, vis, path);
                if (!path.empty()) {
                    path.push_back(u);
                    return;
                }
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        cin >> T;
        for (int t = 1; t <= T; ++t) {
            int n;
            cin >> n;
            vector<vector<int>> g(n);
            for (int i = 0; i < n - 1; ++i) {
                int a, b;
                cin >> a >> b;
                g[a - 1].push_back(b - 1);
                g[b - 1].push_back(a - 1);
            }
            int k1;
            cin >> k1;
            set<int> sx;
            vector<int> x(k1);
            for (int i = 0; i < k1; ++i) {
                cin >> x[i];
                --x[i];
                sx.insert(x[i]);
            }
            int k2;
            cin >> k2;
            set<int> sy;
            vector<int> y(k2);
            for (int i = 0; i < k2; ++i) {
                cin >> y[i];
                --y[i];
                sy.insert(y[i]);
            }
            int u1 = x[0];
            int v2 = y[0];
            int u2 = query('B', v2);
            vector<int> vis(n, 0), path;
            if (sx.count(u2)) {
                query('C', u2);
                goto nxtit;
            }
            dfs(u1, u2, g, vis, path);
            assert(!path.empty());
            reverse(begin(path), end(path));
            for (int i = 0; i + 1 < (int)path.size(); ++i) {
                if (sx.count(path[i + 1]) == 0) {
                    assert(sx.count(path[i]));
                    int u3 = path[i];
                    int v3 = query('A', u3);
                    if (sy.count(v3)) {
                        query('C', u3);
                    } else {
                        query('C', -2);
                    }
                    goto nxtit;
                }
            }
            assert(false);
            nxtit:;
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
