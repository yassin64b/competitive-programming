#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        map<i64, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            m[a[i]].push_back(i);
        }
        vector<pair<int, i64>> res;
        for (auto &[k, v] : m) {
            sort(begin(v), end(v));
            for (int i = 0; i < (int)v.size(); i += 2) {
                if (i + 1 < (int)v.size()) {
                    m[2 * k].push_back(v[i + 1]);
                } else {
                    res.emplace_back(v[i], k);
                }
            }
        }
        out << res.size() << "\n";
        sort(begin(res), end(res));
        for (auto [x, y] : res) {
            out << y << " ";
        }
        out << "\n";
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
