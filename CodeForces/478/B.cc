#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        constexpr int n = 14;
        vector<i64> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        i64 mx = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                continue;
            }
            i64 num = a[i] / n;
            i64 rest = a[i] % n;
            vector<i64> b(a);
            b[i] = 0;
            for (int j = 0; j < n; ++j) {
                b[j] += num;
            }
            for (int j = i + 1; j <= i + rest; ++j) {
                b[j % n] += 1;
            }
            i64 cur = 0;
            for (i64 x : b) {
                cur += (x % 2 == 0) * x;
            }
            mx = max(mx, cur);
        }
        out << mx << "\n";
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