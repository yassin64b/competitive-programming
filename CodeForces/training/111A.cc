#include <bits/stdc++.h>

using namespace std;

class A111 {
public:
    void solve(istream& in, ostream& out) {
        int n, y;
        long long x;
        in >> n >> x >> y;
        vector<int> a(n, 1);
        long long need = max(x - (n - 1), 1LL);
        int last = sqrt(need);
        if (1LL * last * last + n - 1 < x) {
            ++last;
        }
        a[0] = last;
        if (last + n - 1 > y) {
            out << -1 << "\n";
            return;
        }
        for (int z : a) {
            out << z << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A111 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
