#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        sort(begin(a), end(a));
        if (k == 0) {
            if (a[0] == 1) {
                out << -1 << "\n";
            } else {
                out << 1 << "\n";
            }
            return;
        }
        int ans = a[k - 1], num = 0;
        for (int x : a) {
            num += (x <= ans);
        }
        if (num != k) {
            out << - 1 << "\n";
        } else {
            out << ans << "\n";
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
