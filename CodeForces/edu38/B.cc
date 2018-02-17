#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        constexpr int p1 = 1, p2 = 1'000'000;
        int mn_sec = min(a.back() - p1, p2 - a[0]);
        for (int i = 0; i + 1 < n; ++i) {
            mn_sec = min(mn_sec, max(a[i] - p1, p2 - a[i + 1]));
        }
        out << mn_sec << "\n";
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
