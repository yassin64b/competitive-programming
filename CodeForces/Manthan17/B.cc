#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        long long p, q, r;
        in >> n >> p >> q >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        // prefix max, suffix max, prefix min, suffix min
        vector<int> pmx(n, 0), smx(n, 0), pmn(n, 0), smn(n, 0);
        pmx[0] = pmn[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pmx[i] = max(a[i], pmx[i - 1]);
            pmn[i] = min(a[i], pmn[i - 1]);
        }
        smx[n - 1] = smn[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            smx[i] = max(a[i], smx[i + 1]);
            smn[i] = min(a[i], smn[i + 1]);
        }
        long long res = 3 * -1'000'000'000LL * 1'000'000'000;
        for (int j = 0; j < n; ++j) {
            long long val = q * a[j];
            if (p < 0) {
                val += p * pmn[j];
            } else {
                val += p * pmx[j];
            }
            if (r < 0) {
                val += r * smn[j];
            } else {
                val += r * smx[j];
            }
            res = max(res, val);
        }
        out << res << "\n";
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
