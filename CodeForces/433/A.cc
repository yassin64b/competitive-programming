#include <bits/stdc++.h>

using namespace std;

class TaskA {
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        for (int denom = n / 2 + n % 2; denom < n; ++denom) {
            int num = n - denom;
            if (gcd(num, denom) == 1) {
                out << num << " " << denom << "\n";
                return;
            }
        }
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
