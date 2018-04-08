#include <bits/stdc++.h>

using namespace std;

class C570 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        string s;
        in >> s;
        int res = 0;
        for (int i = 1; i < n; ++i) {
            res += (s[i] == '.' && s[i - 1] == '.');
        }
        for (int i = 0; i < m; ++i) {
            int x;
            char c;
            in >> x >> c;
            --x;
            int add = 0;
            if (c == '.') {
                if (s[x] != '.') {
                    add += (x > 0 && s[x - 1] == '.');
                    add += (x + 1 < n && s[x + 1] == '.');
                }
            } else {
                if (s[x] == '.') {
                    add -= (x > 0 && s[x - 1] == '.');
                    add -= (x + 1 < n && s[x + 1] == '.');
                }
            }
            res += add;
            s[x] = c;
            out << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    C570 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
