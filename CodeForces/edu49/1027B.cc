#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        long long n;
        int q;
        in >> n >> q;
        long long a = (n * n + 1) / 2;
        long long even1 = (n + 1) / 2, even2 = n / 2;
        long long odd1 = n / 2, odd2 = (n + 1) / 2;
        for (int i = 0, x, y; i < q; ++i) {
            in >> x >> y;
            long long res = 0;
            if ((x + y) % 2 == 0) {
                if (x % 2 == 1) {
                    int num1 = (x - 1) / 2, num2 = (x - 1) / 2;
                    res += num1 * even1 + num2 * even2;
                    res += (y + 1) / 2;
                } else {
                    int num1 = x / 2, num2 = (x - 1) / 2;
                    res += num1 * even1 + num2 * even2;
                    res += y / 2;
                }
            } else {
                res += a;
                if (x % 2 == 1) {
                    int num1 = (x - 1) / 2, num2 = (x - 1) / 2;
                    res += num1 * odd1 + num2 * odd2;
                    res += y / 2;
                } else {
                    int num1 = x / 2, num2 = (x - 1) / 2;
                    res += num1 * odd1 + num2 * odd2;
                    res += (y + 1) / 2;
                }
            }
            out << res << "\n";
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
