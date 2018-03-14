#include <bits/stdc++.h>

using namespace std;

class dmopc17c5p1 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        map<char, char> m{{'0', 'O'}, {'1', 'l'}, {'3', 'E'}, {'4', 'A'}, {'5', 'S'},
                          {'6', 'G'}, {'8', 'B'}, {'9', 'g'}};
        for (char &c : s) {
            if (m.count(c)) {
                c = m[c];
            }
        }
        out << s << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmopc17c5p1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
