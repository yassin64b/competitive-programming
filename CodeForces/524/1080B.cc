#include <bits/stdc++.h>

using namespace std;

class TaskB {
private:
    long long sum(long long r) {
        return r * (r + 1) / 2;
    }
public:
    void solve(istream& in, ostream& out) {
        // odd pos negative
        int q;
        in >> q;
        for (int i = 0; i < q; ++i) {
            long long l, r;
            in >> l >> r;
            long long sum_all = sum(r) - sum(l - 1);
            long long sum_even = 2 * sum(r / 2) - 2 * sum((l - 1) / 2);
            out << sum_even - (sum_all - sum_even) << "\n";
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
