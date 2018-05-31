#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        map<long long, int> m;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, ++m[a[i]]);
        }
        out << n - mx << "\n";
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
