#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int x = 0;
        for (int i = 0; i < n; ++i) {
            a[i] %= k;
            x = gcd(x, a[i]);
        }
        set<int> s;
        for (int i = 0; i < k; ++i) {
            s.insert(1LL * x * i % k);
        }
        out << s.size() << "\n";
        for (int i : s) {
            out << i << " ";
        }
        out << "\n";
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
