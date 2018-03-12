#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int a, b;
        in >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        int len = b - a, res = 0;
        for (int i = 0; i < (len + 1) / 2; ++i) res += i + 1;
        for (int i = 0; i < len / 2; ++i) res += i + 1;
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
