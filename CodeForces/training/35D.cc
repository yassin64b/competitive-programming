#include <bits/stdc++.h>

using namespace std;

class D35 {
public:
    void solve(istream& in, ostream& out) {
        int n, X;
        in >> n >> X;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            in >> c[i];
        }
        for (int i = 0; i < n; ++i) {
            c[i] *= n - i;
        }
        sort(begin(c), end(c));
        int res = 0;
        for (int i = 0; i < n; ++i) {
            X -= c[i];
            if (X >= 0) {
                ++res;
            } else {
                break;
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D35 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
