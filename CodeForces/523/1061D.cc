#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        i64 x, y;
        in >> n >> x >> y;
        vector<pair<int, int>> lr(n);
        for (int i = 0, l, r; i < n; ++i) {
            in >> l >> r;
            lr[i] = {l, r};
        }
        sort(begin(lr), end(lr));
        constexpr int MOD = 1'000'000'007;
        multiset<int> standby;
        i64 res = 0;
        for (int i = 0; i < n; ++i) {
            int a = lr[i].first, b = lr[i].second;
            auto it = standby.lower_bound(a);
            bool done = false;
            i64 cost2 = x + y * (b - a);
            if (it != begin(standby)) {
                int last = *--it;
                i64 cost1 = y * (b - last);
                if (cost1 < cost2) {
                    done = true;
                    res = (res + cost1) % MOD;
                    standby.erase(it);
                }
            }
            if (!done) {
                res = (res + cost2) % MOD;
            }
            standby.insert(b);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
