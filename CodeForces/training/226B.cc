#include <bits/stdc++.h>

using namespace std;

class B226 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        sort(begin(a), end(a));
        reverse(begin(a), end(a));
        vector<long long> pre_sum_a(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre_sum_a[i + 1] = pre_sum_a[i] + a[i];
        }
        vector<long long> res(n, 0);
        for (int k = 1; k < n; ++k) {
            for (long long i = 1, mult = 1, add = k; i < n; ++mult, add *= k) {
                long long cur = pre_sum_a[min(i + add, (long long)n)] - pre_sum_a[i];
                res[k] += mult * cur;
                i += add;
            }
        }
        int q;
        in >> q;
        for (int i = 0; i < q; ++i) {
            int k;
            in >> k;
            out << res[min(k, n - 1)] << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B226 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
