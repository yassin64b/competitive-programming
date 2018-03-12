#include <bits/stdc++.h>

using namespace std;

class B556 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int turn = a[0];
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                a[i] = (a[i] - turn + n) % n;
            } else {
                a[i] = (a[i] + turn) % n;
            }
            if (a[i] != i) {
                out << "No\n";
                return;
            }
        }
        out << "Yes\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B556 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
