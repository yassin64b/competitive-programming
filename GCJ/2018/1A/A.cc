#include <bits/stdc++.h>

using namespace std;

class gcj_waffle_choppers {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int R, C, H, V;
            in >> R >> C >> H >> V;
            vector<string> waffle(R);
            int sum = 0;
            for (int i = 0; i < R; ++i) {
                in >> waffle[i];
                for (int j = 0; j < C; ++j) {
                    sum += (waffle[i][j] == '@');
                }
            }
            out << "Case #" << t << ": ";
            int num_comp = (H + 1) * (V + 1);
            if (sum % num_comp) {
                out << "IMPOSSIBLE\n";
                continue;
            } else if (sum == 0) {
                out << "POSSIBLE\n";
                continue;
            }
            sum /= num_comp;
            vector<int> rows{-1};
            for (int i = 0, cur = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    cur += (waffle[i][j] == '@');
                }
                if (cur >= sum * (V + 1)) {
                    cur = 0;
                    rows.push_back(i);
                }
            }
            if ((int)rows.size() != H + 2) {
                out << "IMPOSSIBLE\n";
                continue;
            }
            vector<int> cols{-1};
            for (int j = 0, cur = 0; j < C; ++j) {
                for (int i = 0; i < R; ++i) {
                    cur += (waffle[i][j] == '@');
                }
                if (cur >= sum * (H + 1)) {
                    cur = 0;
                    cols.push_back(j);
                }
            }
            if ((int)cols.size() != V + 2) {
                out << "IMPOSSIBLE\n";
                continue;
            }
            bool ok = true;
            for (int i = 0; i <= H; ++i) {
                for (int j = 0; j <= V; ++j) {
                    int cur = 0;
                    for (int r = rows[i] + 1; r <= rows[i + 1]; ++r) {
                        for (int c = cols[j] + 1; c <= cols[j + 1]; ++c) {
                            cur += (waffle[r][c] == '@');
                        }
                    }
                    if (cur != sum) {
                        ok = false;
                    }
                }
            }
            out << (ok ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_waffle_choppers solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
