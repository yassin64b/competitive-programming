#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<i64> b(n / 2);
        for (int i = 0; i < n / 2; ++i) {
            in >> b[i];
        }
        vector<i64> a(n);
        a[n / 2 - 1] = b[n / 2 - 1] / 2;
        a[n / 2] = b[n / 2 - 1] - a[n / 2 - 1];
        for (int i = n / 2 - 2; i >= 0; --i) {
            int j = n - 1 - i;
            a[i] = min(a[i + 1], b[i] / 2);
            a[j] = b[i] - a[i];
            if (a[j] < a[j - 1]) {
                a[j] = a[j - 1];
                a[i] = b[i] - a[j];
            }
        }
        for (int i = 0; i < n; ++i) {
            out << a[i] << " ";
        }
        out << "\n";
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
