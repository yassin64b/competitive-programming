#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    int dfs(int u, const vector<set<int>> &g, set<int> &unvis) {
        unvis.erase(u);
        int sz = 1, v = -1;
        while (true) {
            auto it = unvis.upper_bound(v);
            if (it == unvis.end()) {
                break;
            }
            v = *it;
            if (!g[u].count(v)) {
                sz += dfs(v, g, unvis);
            }
        }
        return sz;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<set<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].insert(v - 1);
            g[v - 1].insert(u - 1);
        }
        set<int> unvis;
        for (int u = 0; u < n; ++u) {
            unvis.insert(u);
        }
        vector<int> res;
        for (int u = 0; u < n; ++u) {
            if (unvis.count(u)) {
                res.push_back(dfs(u, g, unvis));
            }
        }
        out << res.size() << "\n";
        sort(begin(res), end(res));
        for (int x : res) {
            out << x << " ";
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
