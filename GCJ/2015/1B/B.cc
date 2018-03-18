#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1'000'000;

class gcj_noisy_neighbors {
private:
    int solve_small(int R, int C, int N) {
        vector<vector<int>> occ(R, vector<int>(C, 0));
        return brute(0, 0, R, C, N, occ);
    }
    int brute(int x, int y, int R, int C, int N, vector<vector<int>> &occ) {
        if (y == C) {
            y = 0;
            ++x;
        }
        if (N == 0) {
            int res = 0;
            for (int i = 0; i < R; ++i)
                for (int j = 0; j + 1 < C; ++j)
                    res += occ[i][j] && occ[i][j + 1];
            for (int i = 0; i + 1 < R; ++i)
                for (int j = 0; j < C; ++j)
                    res += occ[i][j] && occ[i + 1][j];
            return res;
        } else if (x >= R) {
            return INF;
        }
        int a = brute(x, y + 1, R, C, N, occ);
        occ[x][y] = 1;
        int b = brute(x, y + 1, R, C, N - 1, occ);
        occ[x][y] = 0;
        return min(a, b);
    }
    int solve_large(int R, int C, int N) {
        if (2 * N <= R * C + 1) return 0;
        vector<vector<int>> g(R, vector<int>(C, 0));
        for (int i = 0; i < R; ++i) {
            if (i % 2 == 0) for (int j = 0; j < C; j += 2) g[i][j] = 1;
            if (i % 2 == 1) for (int j = 1; j < C; j += 2) g[i][j] = 1;
        }
        int res = solve_grid(g, R, C, R * C - N);
        g.assign(R, vector<int>(C, 0));
        for (int i = 0; i < R; ++i) {
            if (i % 2 == 1) for (int j = 0; j < C; j += 2) g[i][j] = 1;
            if (i % 2 == 0) for (int j = 1; j < C; j += 2) g[i][j] = 1;
        }
        res = max(res, solve_grid(g, R, C, R * C - N));
        int unhappiness = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j + 1 < C; ++j)
                ++unhappiness;
        for (int i = 0; i + 1 < R; ++i)
            for (int j = 0; j < C; ++j)
                ++unhappiness;
        assert(unhappiness == (R - 1) * C + R * (C - 1));
        return unhappiness - res;
    }
    int solve_grid(vector<vector<int>> &g, int R, int C, int mx) {
        int res = 0;
        for (int z = 0; z < mx; ++z) {
            int x = -1, y = -1, best = 0;
            for (int i = 0; i < R; ++i) 
                for (int j = 0; j < C; ++j)
                    if (g[i][j] && num_neighbors(i, j, R, C) > best)
                        best = num_neighbors(i, j, R, C), x = i, y = j;
            assert(x != -1 && y != -1);
            g[x][y] = 0;
            res += num_neighbors(x, y, R, C);
        }
        return res;
    }
    int num_neighbors(int i, int j, int R, int C) {
        int res = (i > 0) + (i < R - 1) + (j > 0) + (j < C - 1);
        return res;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int R, C, N;
            in >> R >> C >> N;
            out << "Case #" << t << ": " << solve_large(R, C, N) << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_noisy_neighbors solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
