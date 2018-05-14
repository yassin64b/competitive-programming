#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            if (i > 0) {
                a[i] += a[i - 1];
            }
        }
        for (int i = 0; i < m; ++i) {
            long long b;
            in >> b;
            auto it = lower_bound(begin(a), end(a), b);
            int f = it - begin(a) + 1;
            long long k = b;
            if (f >= 2) {
                k = b - a[f - 2];
            }
            out << f << " " << k << "\n";
        }
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
