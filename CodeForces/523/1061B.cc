#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        long long res = 0;
        sort(begin(a), end(a));
        int cov_to = 0;
        for (int i = 0; i < n - 1; ++i) {
            res += max(a[i] - 1, 0);
            if (a[i] > 0) {
                cov_to = min(cov_to + 1, a[i]);
            }
        }
        res += max(0, min(a[n - 1] - 1, cov_to));
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
