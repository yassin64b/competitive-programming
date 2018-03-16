#include <bits/stdc++.h>

using namespace std;

class gcj_ominous_omino {
private:
    const int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
    const int G_SZ = 13;
    inline bool valid(int x, int y) {
        return x >= 0 && x < y;
    }
    bool richard(int X, int R, int C) {
        if (X >= 7 || R * C % X != 0) {
            return true;
        }
        vector<vector<vector<int>>> ominos;
        gen_ominos(X, ominos);
        for (const auto &grid : ominos) {
            if (!gabriel(X, R, C, grid) && !gabriel(X, C, R, grid)) {
                return true;
            }
        }
        return false;
    }
    bool gabriel(int X, int R, int C, const vector<vector<int>> &grid) {
        for (int a = -G_SZ; a <= G_SZ; ++a) {
            for (int b = -G_SZ; b <= G_SZ; ++b) {
                vector<vector<int>> cur(R, vector<int>(C, 0));
                bool ok = true;
                for (int i = 0; i < G_SZ; ++i) {
                    for (int j = 0; j < G_SZ; ++j) {
                        if (grid[i][j]) {
                            if (valid(i + a, R) && valid(j + b, C)) {
                                cur[i + a][j + b] = 1;
                            } else {
                                ok = false;
                            }
                        }
                        
                    }
                }
                if (ok) {
                    if (test(X, R, C, cur)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool test(int X, int R, int C, vector<vector<int>> &grid) {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (!grid[i][j]) {
                    int sz = dfs(i, j, R, C, grid);
                    if (sz % X != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    int dfs(int i, int j, int R, int C, vector<vector<int>> &grid) {
        grid[i][j] = 2;
        int res = 1;
        for (int d = 0; d < 4; ++d) {
            int ni = i + di[d], nj = j + dj[d];
            if (valid(ni, R) && valid(nj, C) && !grid[ni][nj]) {
                res += dfs(ni, nj, R, C, grid);
            }
        }
        return res;
    }
    void gen_ominos(int X, vector<vector<vector<int>>> &ominos) {
        vector<vector<int>> cur(G_SZ, vector<int>(G_SZ, 0));
        cur[G_SZ / 2][G_SZ / 2] = 1;
        gen_ominos(X - 1, cur, ominos);
    }
    set<vector<vector<int>>> vis;
    void gen_ominos(int X, vector<vector<int>> &cur, vector<vector<vector<int>>> &ominos) {
        if (X == 0) {
            ominos.push_back(cur);
            return;
        }
        if (vis.count(cur)) {
            return;
        }
        vis.insert(cur);
        for (int i = 0; i < G_SZ; ++i) {
            for (int j = 0; j < G_SZ; ++j) {
                if (!cur[i][j]) continue;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + di[d], nj = j + dj[d];
                    if (valid(ni, G_SZ) && valid(nj, G_SZ) && !cur[ni][nj]) {
                        cur[ni][nj] = 1;
                        gen_ominos(X - 1, cur, ominos);
                        cur[ni][nj] = 0;
                    }
                }
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int X, R, C;
            in >> X >> R >> C;
            vis.clear();
            out << "Case #" << t << ": " << (richard(X, R, C) ? "RICHARD\n" : "GABRIEL\n");
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_ominous_omino solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
