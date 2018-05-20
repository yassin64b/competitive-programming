#include <bits/stdc++.h>

using namespace std;

class agc024d {
private:
    void dfs(int u, const vector<vector<int>> &g, vector<int> &vis,
            vector<int> &cnt, int h, int &mx)
    {
        vis[u] = 1;
        cnt[h] = max(cnt[h], (int)g[u].size());
        mx = max(mx, h);
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, g, vis, cnt, h + 1, mx);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        if (N == 2) {
            out << 1 << " " << 2 << "\n";
            return;
        }
        vector<vector<int>> g(N);
        for (int i = 0; i < N - 1; ++i) {
            int a, b;
            in >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        int col = N + 1;
        long long leaves = 0;
        for (int r = 0; r < N; ++r) {
            vector<int> cnt(N, 0), vis(N, 0);
            int mxh = 0;
            dfs(r, g, vis, cnt, 0, mxh);
            long long cur = cnt[0];
            for (int i = 1; i < mxh; ++i) {
                cur *= cnt[i] - 1;
            }
            if (mxh + 1 < col) {
                col = mxh + 1;
                leaves = cur;
            } else if (mxh + 1 == col) {
                leaves = min(leaves, cur);
            }
        }
        for (int ra = 0; ra < N; ++ra) {
            for (int rb : g[ra]) {
                vector<vector<int>> tmpg(N);
                for (int u = 0; u < N; ++u) {
                    for (int v : g[u]) {
                        if (!(ra == u && rb == v || ra == v && rb == u)) {
                            tmpg[u].push_back(v);
                        }
                    }
                }
                vector<int> cnt(N, 0), vis(N, 0);
                int mxh = 0;
                dfs(ra, tmpg, vis, cnt, 0, mxh);
                dfs(rb, tmpg, vis, cnt, 0, mxh);
                long long cur = cnt[0] * 2;
                for (int i = 1; i < mxh; ++i) {
                    cur *= cnt[i] - 1;
                }
                if (mxh + 1 < col) {
                    col = mxh + 1;
                    leaves = cur;
                } else if (mxh + 1 == col) {
                    leaves = min(leaves, cur);
                }
            }
        }
        out << col << " " << leaves << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc024d solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
