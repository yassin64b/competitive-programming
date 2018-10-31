#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, M;
        in >> n >> M;
        vector<int> a(n + 1);
        a[0] = 0;
        for (int i = 0; i < n; ++i) {
            in >> a[i + 1];
        }
        a.push_back(M);
        vector<int> suf(n + 1);
        if (n % 2 == 0) {
            suf[n] = M - a[n];
        } else {
            suf[n] = 0;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i % 2 == 0) {
                suf[i] = suf[i + 1] + a[i + 1] - a[i];
            } else {
                suf[i] = suf[i + 1];
            }
        }
        int res = max(suf[0], (a[1] > 1 ? M - suf[0] - 1 : 0));
        if (n % 2 == 1) {
            res = max(res, suf[0] + M - a[n] - 1);
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] - a[i - 1] > 1) {
                res = max(res, suf[0] - suf[i] + M - a[i] - 1 - suf[i]);
            }
            if (a[i + 1] - a[i] > 1) {
                res = max(res, suf[0] - suf[i] + M - a[i] - 1 - suf[i]);
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