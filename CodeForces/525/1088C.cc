#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        out << n + 1 << "\n";
        long long add = 0;
        for (int i = n - 1; i >= 0; --i) {
            a[i] += add;
            if (a[i] % n <= i) {
                add += i - a[i] % n;
                out << 1 << " " << i + 1 << " " << i - a[i] % n << "\n";
            } else {
                add += n - a[i] % n + i;
                out << 1 << " " << i + 1 << " " << n - a[i] % n + i << "\n";
            }
        }
        out << 2 << " " << n << " " << n << "\n";
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
