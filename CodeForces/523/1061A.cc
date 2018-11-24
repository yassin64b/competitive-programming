#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, S;
        in >> n >> S;
        int res = 0;
        for (int i = n; i >= 1; --i) {
            int cnt = S / i;
            S -= cnt * i;
            res += cnt;
        }
        out << res << "\n";
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
