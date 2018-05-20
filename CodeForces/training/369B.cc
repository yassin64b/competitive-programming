#include <bits/stdc++.h>

using namespace std;

class B369 {
public:
    void solve(istream& in, ostream& out) {
        int n, k, l, r, sall, sk;
        in >> n >> k >> l >> r >> sall >> sk;
        vector<int> res(n, 0);
        int cur = 0;
        for (int i = 0; i < k; ++i) {
            res[i] = sk / k;
            cur += res[i];
        }
        for (int i = 0; i < k && cur < sk; ++i) {
            ++res[i];
            ++cur;
        }
        int sr = sall - sk;
        for (int i = k; i < n; ++i) {
            res[i] = sr / (n - k);
            cur += res[i];
        }
        for (int i = k; i < n && cur < sall; ++i) {
            ++res[i];
            ++cur;
        }
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B369 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
