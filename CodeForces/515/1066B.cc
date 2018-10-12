#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, r;
        in >> n >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int cov_to = -1, res = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (cov_to < i) {
                int ind = -1;
                for (; j < n && j < i + r; ++j) {
                    if (a[j]) {
                        ind = j;
                    }
                }
                if (ind == -1) {
                    out << -1 << "\n";
                    return;
                }
                ++res;
                cov_to = ind + r - 1;
            }
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
