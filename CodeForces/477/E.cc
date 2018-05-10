#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<i64> b(n);
        vector<vector<i64>> q(60);
        for (int i = 0; i < n; ++i) {
            in >> b[i];
            int msb = 0;
            for (i64 x = b[i]; x; x >>= 1, ++msb);
            q[msb - 1].push_back(b[i]);
        }
        vector<i64> res;
        i64 cur = 0;
        for (int i = 0; i < n; ++i) {
            i64 x = 0;
            for (int j = 0; j < 60; ++j) {
                if (!q[j].empty() && (cur & (1LL << j)) == 0) {
                    x = q[j].back();
                    q[j].pop_back();
                    break;
                }
            }
            if (x == 0) {
                out << "No\n";
                return;
            }
            cur ^= x;
            res.push_back(x);
        }
        out << "Yes\n";
        for (i64 x : res) {
            out << x << " ";
        }
        out << "\n";
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
