#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            in >> r[i];
        }
        for (int i = 1; i < n; ++i) {
            r[i] += r[i - 1];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int cnt = r[j] - (i > 0 ? r[i - 1] : 0);
                int t = (j - i + 1);
                if (cnt > t * 100) {
                    res = max(res, t);
                }
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
