#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        for (int i = 1; i + 1 < n; ++i) {
            if (s[i - 1] != '.' && s[i] != '.' && s[i + 1] != '.') {
                if (s[i - 1] != s[i] && s[i - 1] != s[i + 1] && s[i] != s[i + 1]) {
                    out << "Yes\n";
                    return;
                }
            }
        }
        out << "No\n";
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
