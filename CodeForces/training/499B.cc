#include <bits/stdc++.h>

using namespace std;

class B499 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        map<string, string> ab;
        for (int i = 0; i < m; ++i) {
            string a, b;
            in >> a >> b;
            ab[a] = b;
        }
        for (int i = 0; i < n; ++i) {
            string c;
            in >> c;
            if (ab[c].size() < c.size()) {
                out << ab[c] << " ";
            } else {
                out << c << " ";
            }
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B499 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
