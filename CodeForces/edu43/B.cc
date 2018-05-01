#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        i64 n, m, k;
        in >> n >> m >> k;
        if (k < n) { // first column down
            out << 1 + k << " " << 1 << "\n";
            return;
        }
        // at (n, 1)
        k -= n;
        i64 len = m - 1;
        i64 num = k / len;
        i64 row = n - num, col;
        if (row % 2 == 0) {
            col = 2 + k % len;
        } else {
            col = m - k % len;
        }
        assert(row >= 1 && row <= n && col >= 2 && col <= m);
        out << row << " " << col << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
