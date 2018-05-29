#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n), x(n);
        map<int, int> res;
        for (int i = 0; i < n; ++i) {
            in >> a[i] >> x[i];
            res[a[i]] = x[i];
        }
        int m;
        in >> m;
        vector<int> b(m), y(m);
        for (int j = 0; j < m; ++j) {
            in >> b[j] >> y[j];
            res[b[j]] = max(res[b[j]], y[j]);
        }
        long long ans = 0;
        for (auto [k, v] : res) {
            ans += v;
        }
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
