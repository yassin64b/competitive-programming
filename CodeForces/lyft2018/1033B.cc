#include <bits/stdc++.h>

using namespace std;

class TaskB {
private:
    bool is_prime(long long x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (long long i = 3; i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }
public:
    void solve(istream& in, ostream& out) {
        int t;
        in >> t;
        for (int i = 1; i <= t; ++i) {
            long long a, b;
            in >> a >> b;
            long long p = a + b;
            if (a - b == 1 && is_prime(p)) {
                out << "YES\n";
            } else {
                out << "NO\n";
            }
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
