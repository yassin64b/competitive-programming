#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n + 1);
        a[0] = 0;
        for (int i = 1; i <= n; ++i) {
            in >> a[i];
        }
        vector<int> res;
        for (int k = 1; k <= n; ++k) {
            vector<int> x(k);
            for (int i = 0; i < k; ++i) {
                x[i] = a[i + 1] - a[i];
            }
            bool ok = true;
            for (int i = 1; i <= n; ++i) {
                if (a[i] != x[(i - 1) % k] + a[i - 1]) {
                    ok = false;
                }
            }
            if (ok) {
                res.push_back(k);
            }
        }
        out << res.size() << "\n";
        for (int k : res) {
            out << k << " ";
        }
        out << "\n";
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
