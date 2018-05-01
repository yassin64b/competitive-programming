#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n, a, b;
        in >> n >> a >> b;
        vector<i64> hp(n), dmg(n);
        vector<pair<i64, i64>> v(n);
        for (int i = 0; i < n; ++i) {
            in >> hp[i] >> dmg[i];
            v[i] = {hp[i], dmg[i]};
        }
        
        sort(begin(v), end(v), [](const auto &lhs, const auto &rhs) {
            return lhs.first - lhs.second < rhs.first - rhs.second;
        });
        reverse(begin(v), end(v));
        
        vector<pair<i64, i64>> pre(n + 1);
        pre[0] = {0, 0};
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = {v[i].first + pre[i].first, v[i].second + pre[i].second};
        }
        i64 ans = accumulate(begin(dmg), end(dmg), 0LL);
        if (b == 0) {
            out << ans << "\n";
            return;
        }
    
        b = min(b, n);
        int bb = b;
        for (int upto = 0; upto < n; ++upto) {
            if (v[upto].first < v[upto].second) {
                b = min(b, upto);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            i64 cur = 0;
            if (i < b) {
                cur = pre[b].first + pre[n].second - pre[b].second - v[i].first + (v[i].first << a);
            } else {
                int c = min(bb - 1, b);
                cur = pre[c].first + pre[n].second - pre[c].second - v[i].second + (v[i].first << a);
            }
            ans = max(ans, cur);
        }
        out << ans << "\n";
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
