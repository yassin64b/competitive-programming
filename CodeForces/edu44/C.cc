#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, k, l;
        in >> n >> k >> l;
        int m = n * k;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            in >> a[i];
        }
        sort(begin(a), end(a));
        int mn = a[0];
        auto it = upper_bound(begin(a), end(a), mn + l);
        int num = it - begin(a);
        if (num < n) {
            out << 0 << "\n";
            return;
        }
        vector<int> res(n, 1'000'000'001);
        for (int i = n - 1, j = m - 1; i >= 0; --i) {
            for (int c = 1; c < k; ++c) {
                while (a[j] == 0) --j;
                res[i] = min(res[i], a[j]);
                --j;
            }
            while (a[j] == 0) --j;
            if (res[i] > mn + l && a[j] > mn + l) {
                res[i] = a[--num];
                a[num] = 0;
            } else {
                res[i] = min(res[i], a[j]);
                --j;
            }
        }
        long long ans = 0;
        for (int x : res) {
            ans += x;
        }
        out << ans << "\n";
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
