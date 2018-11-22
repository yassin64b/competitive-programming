#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream &in, ostream &out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        constexpr int MX = 100 * 100;
        vector<vector<pair<int, int>>> v(MX + 1,
                                         vector<pair<int, int>>(101, {101, -1}));
        v[0][0] = {100, 0};
        for (int i = 0; i < n; ++i) {
            for (int j = MX - a[i]; j >= 0; --j) {
                for (int k = 0; k < 100; ++k) {
                    if (v[j][k].first != 101) {
                        v[j + a[i]][k + 1].first = min(v[j + a[i]][k + 1].first,
                                                       min(v[j][k].first, a[i]));
                        v[j + a[i]][k + 1].second = max(v[j + a[i]][k + 1].second,
                                                       max(v[j][k].second, a[i]));
                    }
                }
            }
        }
        int res = 0;
        for (int j = 1; j <= MX; ++j) {
            for (int k = 1; k <= 100; ++k) {
                if (v[j][k].first == v[j][k].second) {
                    res = max(res, k);
                }
            }
        }
        set<int> tmpa(begin(a), end(a));
        if (tmpa.size() == 2U) {
            res = n;
        }
        out << res << "\n";
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
