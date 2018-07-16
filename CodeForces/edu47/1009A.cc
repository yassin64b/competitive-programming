#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            in >> c[i];
        }
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            in >> a[i];
        }
        int res = 0;
        for (int i = 0, j = 0; i < n && j < m; ++i) {
            if (c[i] <= a[j]) {
                ++res;
                ++j;
            }
        }
        out << res << "\n";
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
