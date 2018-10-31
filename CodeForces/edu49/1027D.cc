#include <bits/stdc++.h>

using namespace std;

class TaskD {
private:
    void dfs(int u, const vector<int> &a, const vector<int> &c, vector<int> &cur,
            vector<int> &vis, long long &res)
    {
        vis[u] = 2;
        cur.push_back(u);
        if (vis[a[u]] == 2) {
            int mn = c[a[u]];
            while (cur.back() != a[u]) {
                mn = min(mn, c[cur.back()]);
                cur.pop_back();
            }
            res += mn;
        } else if (vis[a[u]] == 0) {
            dfs(a[u], a, c, cur, vis, res);
        }
        vis[u] = 1;
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> c(n), a(n);
        for (int i = 0; i < n; ++i) {
            in >> c[i];
        }
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            --a[i];
        }
        long long res = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vector<int> cur;
                dfs(i, a, c, cur, vis, res);
            }
        }
        out << res << "\n";
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