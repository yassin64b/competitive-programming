#include <bits/stdc++.h>

using namespace std;

class apac_sitting {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int R, C;
            in >> R >> C;
            int res1 = 0;
            for (int i = 0; i < R; i += 3) {
                for (int j = 0; j < C; j += 3) res1 += min(2, C - j);
                if (i + 1 < R) for (int j = 1; j < C; j += 3) res1 += min(2, C - j);
                if (i + 2 < R) {
                    ++res1;
                    for (int j = 2; j < C; j += 3) res1 += min(2, C - j);
                }
            }
            int res5 = 0;
            for (int j = 0; j < C; j += 3) {
                for (int i = 0; i < R; i += 3) res5 += min(2, R - i);
                if (j + 1 < C) for (int i = 1; i < R; i += 3) res5 += min(2, R - i);
                if (j + 2 < C) {
                    ++res5;
                    for (int i = 2; i < R; i += 3) res5 += min(2, R - i);
                }
            }
            res1 = max(res1, res5);
            int res2 = 0;
            for (int i = 0; i < R; i += 3) {
                for (int j = 0; j < C; j += 3) res2 += min(2, C - j);
                if (i + 1 < R) for (int j = 0; j < C; j += 3) res2 += min(2, C - j);
                if (i + 2 < R) for (int j = 0; j + 3 <= C; j += 3) res2 += 1;
            }
            res1 = max(res1, res2);
            int res3 = 0;
            for (int i = 0; i < R; ++i) {
                if (i % 2 == 0)
                    for (int j = 0; j < C; ++j) res3 += (j + 1) % 2;
                else
                    for (int j = 0; j < C; ++j) res3 += j % 2;
            }
            res1 = max(res1, res3);
            out << "Case #" << t << ": " << res1 << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    apac_sitting solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
