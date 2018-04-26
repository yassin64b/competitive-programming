#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        long long n, k, M, D;
        in >> n >> k >> M >> D;
        long long res = 0;
        for (int d = 1; d <= D && d * k <= n; ++d) {
            long long mx_x = min(M, n / ((d - 1) * k + 1));
            res = max(res, mx_x * d);
        }
        out << res << "\n";
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
