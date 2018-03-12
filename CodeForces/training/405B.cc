#include <bits/stdc++.h>

using namespace std;

class B405 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        int last_r = -1, last_l = -1, res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                res += i - last_l - 1;
                last_r = i;
            } else if (s[i] == 'L') {
                if (last_r != -1) {
                    int len = i - last_r + 1;
                    res += len % 2;
                }
                last_l = i;
            }
        }
        if (last_l >= last_r) {
            res += n - last_l - 1;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B405 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
