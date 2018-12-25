#include <bits/stdc++.h>

using namespace std;

bool issq(long long x) {
    long long y = sqrt(x);
    if (y * y < x) ++y;
    if (y * y > x) --y;
    return y * y == x;
}

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> x(n / 2);
        vector<long long> res(n, -1);
        for (int i = 0; i < n / 2; ++i) {
            in >> x[i];
            res[2 * i + 1] = x[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; i += 2) {
            long long a = max(1., sqrt(sum));
            while ((a + 1) * (a + 1) - a * a <= res[i + 1]) {
                if (a * a >= sum && issq(a * a + res[i + 1])) {
                    res[i] = a * a - sum;
                    break;
                }
                ++a;
            }
            if (res[i] == -1) {
                out << "No\n";
                return;
            }
            sum += res[i] + res[i + 1];
        }
        out << "Yes\n";
        for (long long y : res) {
            out << y << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
