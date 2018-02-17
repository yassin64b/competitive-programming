#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int s, f;
        in >> s >> f;
        vector<int> num_part(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int local_s = ((s - i <= 0) ? s - i + n : s - i);
            int local_f = ((f - i <= 0) ? f - i + n : f - i);
            num_part[local_s] += a[i];
            num_part[local_f] -= a[i];
        }
        for (int i = 1; i <= n; ++i) {
            num_part[i] += num_part[i - 1];
        }
        int h = 1;
        for (int i = 2; i <= n; ++i) {
            if (num_part[i] > num_part[h]) {
                h = i;
            }
        }
        out << h << "\n";
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
