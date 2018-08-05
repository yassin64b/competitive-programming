#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            in >> b[i];
        }
        double low = 0., high = 1e9+1, ans = 2e9;
        for (int it = 0; it < 1000; ++it) {
            double mid = (low + high) / 2;
            double cur = mid + m;
            cur -= cur / a[0];
            for (int i = 1; i < n && cur >= m; ++i) {
                cur -= cur / b[i];
                if (cur < m) break;
                cur -= cur / a[i];
            }
            if (cur >= m) {
                cur -= cur / b[0];
            }
            if (cur < m) {
                low = mid;
            } else {
                high = mid;
                ans = mid;
            }
        }
        if (ans > 1.5e9) {
            out << -1 << "\n";
        } else {
            out.precision(17);
            out << fixed << ans << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
