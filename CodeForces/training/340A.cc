#include <bits/stdc++.h>

using namespace std;

class A340 {
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    int f(int x, int l) {
        return x / l;
    }
public:
    void solve(istream& in, ostream& out) {
        int x, y;
        long long a, b;
        in >> x >> y >> a >> b;
        int l = lcm(x, y);
        out << f(b, l) - f(a - 1, l) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A340 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
