#include <bits/stdc++.h>

using namespace std;

class A424 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        int cnt = count(begin(s), end(s), 'x');
        out << abs(n / 2 - cnt) << "\n";
        for (char &c : s) {
            if (cnt < n / 2 && c == 'X') {
                ++cnt;
                c = 'x';
            } else if (cnt > n / 2 && c == 'x') {
                --cnt;
                c = 'X';
            }
        }
        out << s << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A424 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
