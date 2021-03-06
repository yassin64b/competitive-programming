#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            sum += a[i];
        }
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += a[i];
            if (2 * cur >= sum) {
                out << i + 1 << "\n";
                break;
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
