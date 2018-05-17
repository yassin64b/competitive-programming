#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        string t;
        t += s[0];
        t += s[1];
        int res = 0;
        for (int i = 2; i < n; ++i) {
            int m = t.size();
            if (s[i] == 'x' && t[m - 1] == 'x' && t[m - 2] == 'x') {
                ++res;
            } else {
                t += s[i];
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
