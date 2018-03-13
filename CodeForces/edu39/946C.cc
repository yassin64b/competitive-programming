#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        char nxt_c = 'a';
        for (char &c : s) {
            if (c <= nxt_c) {
                c = nxt_c;
                if (++nxt_c > 'z') {
                    out << s << "\n";
                    return;
                }
            }
        }
        out << -1 << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
