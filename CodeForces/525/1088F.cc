#include <bits/stdc++.h>

using namespace std;

class TaskF {
private:
    void dfs(int u, int p, const vector<vector<int>> &g, vector<vector<int>> &st,
            const vector<int> &a, long long &ans, int r)
    {
        st[u][0] = p;
        for (int i = 1; i < 20; ++i) {
            st[u][i] = st[st[u][i - 1]][i - 1];
        }
        if (u != r) {
            long long tmp = a[u] + a[p];
            for (int i = 1; i < 20; ++i) {
                int v = st[u][i];
                tmp = min(tmp, 1LL * i * min(a[u], a[v]) + a[u] + a[v]);
            }
            ans += tmp;
        }
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u, g, st, a, ans, r);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        vector<vector<int>> st(n, vector<int>(20));
        long long ans = 0;
        int r = min_element(begin(a), end(a)) - begin(a);
        dfs(r, r, g, st, a, ans, r);
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskF solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
