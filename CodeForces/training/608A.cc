#include <bits/stdc++.h>

using namespace std;

class A608 {
public:
    void solve(istream& in, ostream& out) {
        int n, s;
        in >> n >> s;
        int res = s;
        for (int i = 0, f, t; i < n; ++i) {
            in >> f >> t;
            res = max(res, t + f);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A608 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
