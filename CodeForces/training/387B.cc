#include <bits/stdc++.h>

using namespace std;

class B387 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            in >> b[i];
        }
        int res = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < m && b[j] < a[i]) {
                ++j;
            }
            if (j == m) {
                ++res;
            } else {
                ++j;
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B387 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
