#include <bits/stdc++.h>

using namespace std;

class arc095_d {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        auto it = max_element(begin(a), end(a));
        int x = *it, y = -1;
        for (int i = 0; i < n; ++i) {
            if (it != a.begin() + i) {
                if (y == -1) {
                    y = a[i];
                } else if (abs(x / 2. - a[i]) < abs(x / 2. - y)) {
                    y = a[i];
                }
            }
        }
        out << x << " " << y << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc095_d solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
