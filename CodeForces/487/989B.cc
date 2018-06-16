#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, p;
        string s;
        in >> n >> p >> s;
        for (int i = 0; i + p < n; ++i) {
            if (s[i] == '.' && s[i + p] == '.') {
                s[i] = '0';
                s[i + p] = '1';
            } else if (s[i] == '.') {
                s[i] = (s[i + p] == '0' ? '1' : '0');
            } else if (s[i + p] == '.') {
                s[i + p] = (s[i] == '0' ? '1' : '0');
            }
        }
        bool ok = false;
        for (int i = 0; i + p < n; ++i) {
            if (s[i] != s[i + p]) {
                ok = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '.') {
                s[i] = '0';
            }
        }
        if (!ok) {
            out << "No\n";
        } else {
            out << s << "\n";
        }
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
