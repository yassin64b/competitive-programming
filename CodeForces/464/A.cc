#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            in >> f[i];
            --f[i];
        }
        for (int i = 0; i < n; ++i) {
            if (f[f[f[i]]] == i) {
                out << "YES\n";
                return;
            }
        }
        out << "NO\n";
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
