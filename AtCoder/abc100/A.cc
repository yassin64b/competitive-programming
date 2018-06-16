#include <bits/stdc++.h>

using namespace std;

class abc100a {
public:
    void solve(istream& in, ostream& out) {
        int A, B;
        in >> A >> B;
        if (A <= 8 && B <= 8) {
            out << "Yay!\n";
        } else {
            out << ":(\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    abc100a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
