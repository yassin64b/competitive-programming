#include <bits/stdc++.h>

using namespace std;

class TaskD {
private:
    void construct(vector<int> d, int n, vector<vector<int>> &g) {
        if (n == 0) {
            g.emplace_back();
            return;
        } else if (n == 1) {
            assert(g.empty());
            for (int j = 0; j < d[0] + 1; ++j) {
                g.emplace_back();
            }
            for (int j = 0; j < d[0] + 1; ++j) {
                for (int i = 0; i < d[0] + 1; ++i) {
                    if (i != j) {
                        g[j].push_back(i);
                    }
                }
            }
            return;
        }
        
        vector<int> dd(n - 2);
        for (int i = 0; i < n - 2; ++i) {
            dd[i] = d[i + 1] - d[0];
        }
        construct(dd, n - 2, g);
        
        int m = g.size();
        for (int j = 0; j < d[n - 1] - d[n - 2] + d[0]; ++j) {
            g.emplace_back();
        }
        int k = m + d[n - 1] - d[n - 2];
        for (int j = k; j < k + d[0]; ++j) {
            for (int i = 0; i < k + d[0]; ++i) {
                if (i != j) {
                    g[j].push_back(i);
                }
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            in >> d[i];
        }
        vector<vector<int>> g;
        construct(d, n, g);
        set<pair<int, int>> e;
        for (int u = 0; u < (int)g.size(); ++u) {
            for (int v : g[u]) {
                e.emplace(min(u, v), max(u, v));
            }
        }
        out << e.size() << "\n";
        for (auto [u, v] : e) {
            out << u + 1 << " " << v + 1 << "\n";
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
