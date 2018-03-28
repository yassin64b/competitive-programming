#include <bits/stdc++.h>

using namespace std;

class B485 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        constexpr int INF = 1'000'000'001;
        int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
        for (int i = 0; i < n; ++i) {
            int x, y;
            in >> x >> y;
            mnx = min(mnx, x);
            mxx = max(mxx, x);
            mny = min(mny, y);
            mxy = max(mxy, y);
        }
        int sidelen = max(mxy - mny, mxx - mnx);
        out << 1LL * sidelen * sidelen << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B485 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
