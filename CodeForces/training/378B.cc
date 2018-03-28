#include <bits/stdc++.h>

using namespace std;

class B378 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i] >> b[i];
        }
        int mxk = n / 2;
        string ra(n, '0'), rb(n, '0');
        for (int i = 0; i < mxk; ++i) {
            ra[i] = rb[i] = '1';
        }
        for (int i = 0, j = 0, cnt = 0; cnt < n; ++cnt) {
            if (a[i] < b[j]) {
                ra[i++] = '1';
            } else {
                rb[j++] = '1';
            }
        }
        out << ra << "\n" << rb << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B378 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
