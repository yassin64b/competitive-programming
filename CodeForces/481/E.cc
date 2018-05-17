#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        long long n, w;
        in >> n >> w;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            if (i > 0) {
                a[i] += a[i - 1];
            }
        }
        long long ans1 = max(-*min_element(begin(a), end(a)), 0LL);
        long long ans2 = min(w - *max_element(begin(a), end(a)), w);
        out << max(ans2 - ans1 + 1, 0LL) << "\n";
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
