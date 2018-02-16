#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        constexpr int MXV = 1'000'000;
        vector<int> g(MXV + 1, 0);
        for (int i = 1; i <= MXV; ++i) {
            int j = i, res = 1;
            while (j) {
                if (j % 10) {
                    res *= j % 10;
                }
                j /= 10;
            }
            if (res >= 10) {
                assert(res < i);
                g[i] = g[res];
            } else {
                g[i] = res;
            }
        }
        vector<vector<int>> cnt(MXV + 1, vector<int>(10, 0));
        for (int i = 1; i <= MXV; ++i) {
            ++cnt[i][g[i]];
        }
        for (int i = 1; i <= MXV; ++i) {
            for (int j = 1; j <= 9; ++j) {
                cnt[i][j] += cnt[i - 1][j];
            }
        }
        int Q;
        in >> Q;
        for (int i = 0; i < Q; ++i) {
            int l, r, k;
            in >> l >> r >> k;
            out << cnt[r][k] - cnt[l - 1][k] << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
