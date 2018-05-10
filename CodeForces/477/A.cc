#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, s;
        in >> n >> s;
        vector<int> t(n);
        for (int i = 0; i < n; ++i) {
            int h, m;
            in >> h >> m;
            t[i] = h * 60 + m;
        }
        int res = -1;
        if (t[0] > s) {
            res = 0;
        } else {
            for (int j = 0; j + 1 < n; ++j) {
                if (t[j + 1] - t[j] > 2 * s + 1) {
                    res = t[j] + s + 1;
                    break;
                }
            }
            if (res == -1) {
                res = t.back() + s + 1;
            }
        }
        out << res / 60 << " " << res % 60 << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
