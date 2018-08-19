#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int n;
            string s;
            in >> n >> s;
            bool ok = true;
            for (int i = 0; i < n / 2; ++i) {
                int d = abs(s[i] - s[n - 1 - i]);
                if (!(d == 0 || d == 2)) {
                    ok = false;
                }
            }
            out << (ok ? "YES\n" : "NO\n");
        }
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
