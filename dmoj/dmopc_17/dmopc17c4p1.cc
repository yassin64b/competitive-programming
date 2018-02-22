#include <bits/stdc++.h>

using namespace std;

class dmopc17c4p1_real {
public:
    void solve(istream& in, ostream& out) {
        int N, Q;
        in >> N >> Q;
        vector<int> ribbon(N + 2, 0);
        for (int i = 0; i < Q; ++i) {
            int x, y;
            in >> x >> y;
            ++ribbon[x];
            --ribbon[y];
        }
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            ribbon[i] += ribbon[i - 1];
        }
        for (int i = 0; i <= N; ++i) {
            res += (ribbon[i] > 0);
        }
        out << N - res << " " << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmopc17c4p1_real solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
