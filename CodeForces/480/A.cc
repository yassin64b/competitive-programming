#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size(), cnto = 0;
        for (char c : s) {
            cnto += (c == 'o');
        }
        if (cnto == 0) {
            out << "YES\n";
            return;
        }
        int cnt_ = n - cnto;
        out << (cnt_ % cnto == 0 ? "YES\n": "NO\n");
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
