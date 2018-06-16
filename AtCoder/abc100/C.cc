#include <bits/stdc++.h>

using namespace std;

class abc100c {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        int res = 0;
        for (int i = 0, a; i < N; ++i) {
            in >> a;
            while (a % 2 == 0) {
                ++res;
                a /= 2;
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    abc100c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
