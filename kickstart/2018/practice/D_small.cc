#include <bits/stdc++.h>

using namespace std;

class kickstart_d {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int n, Q;
            in >> n >> Q;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) {
                in >> a[i];
            }
            vector<int> b;
            for (int i = 0; i < n; ++i) {
                int sum = 0;
                for (int j = i; j < n; ++j) {
                    sum += a[j];
                    b.push_back(sum);
                }
            }
            sort(begin(b), end(b));
            vector<long long> pre_b(b.size() + 1, 0);
            for (int i = 1; i <= (int)b.size(); ++i) {
                pre_b[i] = pre_b[i - 1] + b[i - 1];
            }
            out << "Case #" << t << ":\n";
            for (int q = 0; q < Q; ++q) {
                int l, r;
                in >> l >> r;
                out << pre_b[r] - pre_b[l - 1] << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    kickstart_d solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
