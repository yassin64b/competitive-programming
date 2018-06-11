#include <bits/stdc++.h>

using namespace std;

class A435 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        int cur = 0, res = 1;
        for (int i = 0, a; i < n; ++i) {
            in >> a;
            if (cur + a > m) {
                ++res;
                cur = 0;
            }
            cur += a;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A435 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
