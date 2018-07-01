#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<pair<i64, int>> ev(2 * n);
        for (i64 i = 0, l, r; i < n; ++i) {
            in >> l >> r;
            ev[2 * i] = {l, 0};
            ev[2 * i + 1] = {r + 1, 1};
        }
        vector<i64> res(n + 1, 0);
        int cnt = 0;
        sort(begin(ev), end(ev));
        for (i64 i = 0, last = 0; i < 2 * n; ) {
            i64 cur = ev[i].first;
            res[cnt] += max(0LL, cur - last);
            while (i < 2 * n && ev[i].first == cur && ev[i].second) {
                --cnt;
                ++i;
            }
            while (i < 2 * n && ev[i].first == cur && !ev[i].second) {
                ++cnt;
                ++i;
            }
            last = cur;
        }
        assert(cnt == 0);
        for (int i = 1; i <= n; ++i) {
            out << res[i] << " ";
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
