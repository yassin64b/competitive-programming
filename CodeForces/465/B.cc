#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        int x = 0, y = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'U') {
                ++y;
            } else {
                ++x;
            }
            if (x == y && i + 1 < n && s[i + 1] == s[i]) {
                ++res;
            }
        }
        out << res << "\n";
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
