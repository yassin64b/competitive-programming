#include <bits/stdc++.h>

using namespace std;

class C459 {
private:
    void next(vector<int> &cur, int d, int k) {
        for (int i = 0; i < d; ++i) {
            cur[i] += 1;
            if (cur[i] < k) {
                break;
            } else {
                cur[i] = 0;
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, k, d;
        in >> n >> k >> d;
        k = min(k, n);
        int kd = 1;
        for (int i = 1; i <= d && n > kd; ++i) {
            kd *= k;
        }
        if (n > kd) {
            out << -1 << "\n";
            return;
        }
        vector<vector<int>> res(n);
        vector<int> cur(d, 0);
        for (int i = 0; i < n; ++i) {
            res[i] = cur;
            next(cur, d, k);
        }
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < n; ++j) {
                out << res[j][i] + 1 << " ";
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    C459 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
