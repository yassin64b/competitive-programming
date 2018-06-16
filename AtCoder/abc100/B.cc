#include <bits/stdc++.h>

using namespace std;

class abc100b {
public:
    void solve(istream& in, ostream& out) {
        int D, N;
        in >> D >> N;
        int res = 1;
        for (; N; ++res) {
            bool ok = true;
            int tmp = res;
            for (int j = 0; j < D; ++j) {
                if (tmp % 100) {
                    ok = false;
                }
                tmp /= 100;
            }
            if (tmp % 100 == 0) {
                ok = false;
            }
            N -= ok;
        }
        out << res - 1 << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    abc100b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
