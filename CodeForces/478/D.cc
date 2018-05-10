#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, a, b;
        in >> n >> a >> b;
        map<long long, int> m;
        map<pair<int, int>, int> par;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int x, vx, vy;
            in >> x >> vx >> vy;
            long long val = 1LL * a * vx - vy;
            res += m[val] - par[pair(vx, vy)];
            ++m[val];
            ++par[pair(vx, vy)];
        }
        out << res * 2 << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
