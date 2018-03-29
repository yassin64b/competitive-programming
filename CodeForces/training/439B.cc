#include <bits/stdc++.h>

using namespace std;

class B439 {
public:
    void solve(istream& in, ostream& out) {
        int n, x;
        in >> n >> x;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            in >> c[i];
        }
        sort(begin(c), end(c));
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += 1LL * c[i] * max(1, x--);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B439 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
