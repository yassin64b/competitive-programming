#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        for (int j = 0; j + 1 < n; ++j) {
            if (s[j] == '1' && s[j + 1] == '1') {
                out << "No\n";
                return;
            }
        }
        for (int j = 0; j < n; ++j) {
            bool left = (j == 0 || s[j - 1] == '0');
            bool right = (j == n - 1 || s[j + 1] == '0');
            if (s[j] == '0' && left && right) {
                out << "No\n";
                return;
            }
        }
        out << "Yes\n";
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
