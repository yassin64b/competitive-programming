#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(n), b(m);
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            sum1 ^= a[i];
        }
        for (int i = 0; i < m; ++i) {
            in >> b[i];
            sum2 ^= b[i];
        }
        if (sum1 != sum2) {
            out << "NO\n";
        } else {
            out << "YES\n";
            out << (a[0] ^ sum2 ^ b[0]) << " ";
            for (int i = 1; i < m; ++i) {
                out << b[i] << " ";
            }
            out << "\n";
            for (int i = 1; i < n; ++i) {
                out << a[i] << " ";
                for (int j = 1; j < m; ++j) {
                    out << 0 << " ";
                }
                out << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
