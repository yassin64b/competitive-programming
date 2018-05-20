#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class agc024a {
public:
    void solve(istream& in, ostream& out) {
        i64 A, B, C;
        i64 K;
        in >> A >> B >> C >> K;
        if (K % 2 == 0) {
            out << A - B << "\n";
        } else {
            out << B - A << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc024a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
