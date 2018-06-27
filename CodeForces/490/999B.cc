#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string t;
        in >> n >> t;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                reverse(begin(t), begin(t) + i);
            }
        }
        out << t << "\n";
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
