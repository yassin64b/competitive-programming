#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int sub = 0;
        sort(begin(a), end(a));
        for (int i = 0, j = 0; i < k; ++i) {
            while (j < n && a[j] - sub == 0) {
                ++j;
            }
            if (j < n) {
                out << a[j] - sub << "\n";
                sub = a[j];
                ++j;
            } else {
                out << 0 << "\n";
            }
        }
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
