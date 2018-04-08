#include <bits/stdc++.h>

using namespace std;

class gcj_go_gopher {
private:
    int num_neighbors(int i, int j, const vector<vector<int>> &g) {
        int num = 0;
        for (int ii = i - 1; ii <= i + 1; ++ii) {
            for (int jj = j - 1; jj <= j + 1; ++jj) {
                num += !g[ii][jj];
            }
        }
        return num;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int A;
            in >> A;
            vector<vector<int>> g(11, vector<int>(21, 0));
            for (int k = 0; k < 1000; ++k) {
                int i = 1, j = 1, best = 0;
                for (int ii = 1; ii <= 9; ++ii) {
                    for (int jj = 1; jj <= 19; ++jj) {
                        int cur = num_neighbors(ii, jj, g);
                        if (cur > best) {
                            best = cur;
                            i = ii;
                            j = jj;
                        }
                    }
                }
                assert(best > 0);
                out << i + 1 << " " << j + 1 << "\n";
                out.flush();
                in >> i >> j;
                if (i == 0 && j == 0) {
                    break;
                }
                --i;
                --j;
                g[i][j] = 1;
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_go_gopher solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
