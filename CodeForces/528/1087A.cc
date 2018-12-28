#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        string t, s;
        in >> t;
        int n = t.size();
        for (int i = n - 1, j1 = 0, j2 = n - 1; i >= 0; --i) {
            if (i % 2 == 0) {
                s += t[j1++];
            } else {
                s += t[j2--];
            }
        }
        reverse(begin(s), end(s));
        out << s << "\n";
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
