#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    inline long long sum(long long n) {
        return n * (n - 1) / 2;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<long long> x(m), d(m);
        for (int i = 0; i < m; ++i) {
            in >> x[i] >> d[i];
        }
        long long res = 0;
        for (int i = 0; i < m; ++i) {
            res += n * x[i];
            if (d[i] < 0) {
                if (n % 2 == 1) {
                    res += 2 * sum(n / 2 + 1) * d[i];
                } else {
                    res += sum(n / 2 + 1) * d[i] + sum(n / 2) * d[i];
                }
            } else {
                res += sum(n) * d[i];
            }
        }
        out.precision(17);
        out << fixed << 1. * res / n << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
