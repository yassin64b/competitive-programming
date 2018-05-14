#include <bits/stdc++.h>

using namespace std;

class TaskF {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; ++i) {
            in >> r[i].first;
            r[i].second = i;
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < k; ++i) {
            int x, y;
            in >> x >> y;
            g[x - 1].push_back(y - 1);
            g[y - 1].push_back(x - 1);
        }
        sort(begin(r), end(r));
        reverse(begin(r), end(r));
        set<int> gone;
        vector<int> res(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int u = r[i].second;
            while (j < n && r[j].first == r[i].first) {
                gone.insert(r[j].second);
                ++j;
            }
            int cur = n - j;
            for (int v : g[u]) {
                if (!gone.count(v)) {
                    --cur;
                }
            }
            res[u] = cur;
        }
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
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
