#include <bits/stdc++.h>

using namespace std;

class A371 {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int res = 0;
        for (int i = 0; i < k; ++i) {
            int cnt1 = 0;
            for (int j = i; j < n; j += k) {
                cnt1 += (a[j] == 1);
            }
            int cnt2 = n / k - cnt1;
            res += min(cnt1, cnt2);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A371 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
