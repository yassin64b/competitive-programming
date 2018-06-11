#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<i64> x(n);
        for (int i = 0; i < n; ++i) {
            in >> x[i];
        }
        set<i64> s(begin(x), end(x));
        vector<i64> res{x[0]};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 30; ++j) {
                i64 add = (1LL << j);
                if (s.count(x[i] + add)) {
                    if (s.count(x[i] + 2 * add)) {
                        if (res.size() < 3U) {
                            res = {x[i], x[i] + add, x[i] + 2 * add};
                        }
                    } else {
                        if (res.size() < 2U) {
                            res = {x[i], x[i] + add};
                        }
                    }
                }
            }
        }
        out << res.size() << "\n";
        for (i64 y : res) {
            out << y << " ";
        }
        out << "\n";
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
