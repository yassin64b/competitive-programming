#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 gcd(i64 a, i64 b) {
    return b == 0 ? a : gcd(b, a % b);
}

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        for (int i = 0; i < n; ++i) {
            i64 p, q, b;
            in >> p >> q >> b;
            i64 pqgcd = gcd(p, q);
            p /= pqgcd;
            q /= pqgcd;
            for (i64 tmp = gcd(b, q); tmp != 1; tmp = gcd(b, q)) {
                do {
                    q /= tmp;
                } while (q % tmp == 0);
            }
            out << (q == 1 ? "Finite" : "Infinite") << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
