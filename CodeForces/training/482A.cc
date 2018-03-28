#include <bits/stdc++.h>

using namespace std;

class A482 {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> p(n);
        int i = 0, a = 1, b = n;
        p[0] = a++;
        for (i = 1; i < n && k > 1; ++i, --k) {
            if (i % 2 == 0) {
                p[i] = a++;
            } else {
                p[i] = b--;
            }
        }
        if (i % 2 == 0) {
            for ( ; i < n; ++i) {
                p[i] = b--;
            }
        } else {
            for ( ; i < n; ++i) {
                p[i] = a++;
            }
        }
        
        for (int x : p) {
            out << x << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A482 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
