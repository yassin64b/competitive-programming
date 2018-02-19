#include <bits/stdc++.h>

using namespace std;

class abc088_a {
public:
    void solve(istream& in, ostream& out) {
        int N, A;
        in >> N >> A;
        out << ((N % 500 > A) ? "No" : "Yes") << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    abc088_a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
