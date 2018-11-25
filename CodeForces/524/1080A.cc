#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        long long n, k;
        in >> n >> k;
        long long a = 2 * n, b = 5 * n, c = 8 * n;
        out << ((a + k - 1) / k + (b + k - 1) / k + (c + k - 1) / k) << "\n";
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
