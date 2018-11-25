#include <bits/stdc++.h>

using namespace std;

class A486 {
public:
    void solve(istream& in, ostream& out) {
        long long n;
        in >> n;
        long long res = n / 2;
        if (n % 2 == 1) {
            res -= n;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A486 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
