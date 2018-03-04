#include <bits/stdc++.h>

using namespace std;

class TaskA {
    void dfs(int u, const vector<vector<int>> &g, vector<int> &res, int d) {
        ++res[d];
        for (int v : g[u]) {
            dfs(v, g, res, d + 1);
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int p;
            in >> p;
            g[p - 1].push_back(i + 1);
        }
        vector<int> res(n + 1, 0);
        dfs(0, g, res, 0);
        int ans = 0;
        for (int x : res) ans += x % 2;
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
