#include <bits/stdc++.h>

using namespace std;

class B59 {
public:
    void solve(istream& in, ostream& out) {
        int n, res = 100, sum = 0;
        in >> n;
        for (int i = 0, a; i < n; ++i) {
            in >> a;
            sum += a;
            if (a % 2) {
                res = min(res, a);
            }
        }
        if (sum % 2 == 0) {
            sum -= res;
        }
        out << (sum % 2 ? sum : 0) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B59 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
