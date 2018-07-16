#include <bits/stdc++.h>

using namespace std;

class TaskD {
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        if (m < n - 1) {
            out << "Impossible\n";
            return;
        }
        vector<vector<int>> g(n);
        int cur = n - 1;
        for (int u = 0; u < n - 1; ++u) {
            g[u].push_back(u + 1);
            g[u + 1].push_back(u);
        }
        for (int u = 0; u < n; ++u) {
            for (int v = u + 2; cur < m && v < n; ++v) {
                if (gcd(u + 1, v + 1) == 1) {
                    g[u].push_back(v);
                    g[v].push_back(u);
                    ++cur;
                }
            }
        }
        if (cur < m) {
            out << "Impossible\n";
            return;
        }
        out << "Possible\n";
        for (int u = 0; u < n; ++u) {
            for (int v : g[u]) {
                if (v > u) {
                    out << u + 1 << " " << v + 1 << "\n";
                }
            }
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
