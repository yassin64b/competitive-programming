#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> s(n), r(n);
        vector<vector<int>> v(m);
        for (int i = 0; i < n; ++i) {
            in >> s[i] >> r[i];
            v[s[i] - 1].push_back(r[i]);
        }
        vector<int> res(n, 0);
        for (int i = 0; i < m; ++i) {
            sort(begin(v[i]), end(v[i]));
            reverse(begin(v[i]), end(v[i]));
            int cur = 0;
            for (int j = 0; j < (int)v[i].size(); ++j) {
                cur += v[i][j];
                if (cur > 0) {
                    res[j] += cur;
                }
            }
        }
        out << *max_element(begin(res), end(res)) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
