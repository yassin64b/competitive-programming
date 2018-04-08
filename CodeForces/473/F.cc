#include <bits/stdc++.h>

using namespace std;

class TaskF {
public:
    void solve(istream& in, ostream& out) {
        int n, q;
        in >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<vector<pair<int, int>>> queries(n);
        for (int i = 0; i < q; ++i) {
            int l, x;
            in >> l >> x;
            queries[l - 1].emplace_back(x, i);
        }
        vector<int> cur{0};
        vector<int> incur((1 << 20) + 1, 0);
        incur[0] = 1;
        vector<int> res(q);
        int val = 1;
        constexpr int MOD = 1'000'000'007;
        for (int i = 0; i < n; ++i) {
            if (incur[a[i]]) {
                val *= 2;
                val %= MOD;
            } else {
                int sz = cur.size();
                for (int j = 0; j < sz; ++j) {
                    cur.push_back(cur[j] ^ a[i]);
                    incur[cur.back()] = 1;
                }
            }
            for (auto [x, j] : queries[i]) {
                if (incur[x]) {
                    res[j] = val;
                }
            }
        }
        for (int x : res) {
            out << x << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskF solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
