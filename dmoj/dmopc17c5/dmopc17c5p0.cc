#include <bits/stdc++.h>

using namespace std;

class dmopc17c5p0 {
public:
    void solve(istream& in, ostream& out) {
        int B, P;
        char veg;
        in >> B >> P >> veg;
        if (P * 5 <= B) {
            out << ((veg == 'Y') ? 'B' : 'A') << "\n";
        } else if (P * 2 <= B) {
            out << ((veg == 'Y') ? 'D' : 'C') << "\n";
        } else {
            out << "NO PIZZA\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmopc17c5p0 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
