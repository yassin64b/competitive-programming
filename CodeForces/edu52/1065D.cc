#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<vector<int>> A(N, vector<int>(N));
        vector<pair<int, int>> v(N * N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                in >> A[i][j];
                v[A[i][j] - 1] = pair(i, j);
            }
        }
        constexpr int INF = 1'000'000;
        vector<vector<pair<int, int>>> res(N * N, vector<pair<int, int>>(3, {INF, INF}));
        res[N * N - 1] = {{0, 0}, {0, 0}, {0, 0}};
        for (int i = N * N - 2; i >= 0; --i) {
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[i + 1];
            
            // piece, from, x, y, steps, replacements
            queue<tuple<int, int, int, int, int, int>> q;
            q.emplace(0, 0, x1, y1, 0, 0);
            q.emplace(1, 1, x1, y1, 0, 0);
            q.emplace(2, 2, x1, y1, 0, 0);
            while (!q.empty()) {
                auto [piece, from, x, y, steps, repl] = q.front();
                q.pop();
                if (x == x2 && y == y2) {
                    res[i][from] = min(res[i][from],
                                       pair(res[i + 1][piece].first + steps,
                                            res[i + 1][piece].second + repl));
                    continue;
                }
                // rook
                bool change = (piece != 1);
                for (int i = -N; i <= N; ++i) {
                    int xn = x + i, yn = y + i;
                    if (xn >= 0 && xn < N && steps + change + 1 <= 3 && i) {
                        q.emplace(1, from, xn, y, steps + change + 1, repl + change);
                    }
                    if (yn >= 0 && yn < N && steps + change + 1 <= 3 && i) {
                        q.emplace(1, from, x, yn, steps + change + 1, repl + change);
                    }
                }
                // bishop
                change = (piece != 0);
                for (int i = -N; i <= N; ++i) {
                    int xn = x + i, yn = y + i;
                    if (xn >= 0 && xn < N && yn >= 0 && yn < N && steps + change + 1 <= 3 && i) {
                        q.emplace(0, from, xn, yn, steps + change + 1, repl + change);
                    }
                    xn = x - i, yn = y + i;
                    if (xn >= 0 && xn < N && yn >= 0 && yn < N && steps + change + 1 <= 3 && i) {
                        q.emplace(0, from, xn, yn, steps + change + 1, repl + change);
                    }
                }
                // knight
                change = (piece != 2);
                int dx[] = {2, -2, 1, -1};
                int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        int xn = x + dx[i], yn = y + dy[2 * i + j];
                        if (xn >= 0 && xn < N && yn >= 0 && yn < N && steps + change + 1 <= 3) {
                            q.emplace(2, from, xn, yn, steps + change + 1, repl + change);
                        }
                    }
                }
            }
        }
        pair ans = min(res[0][0], min(res[0][1], res[0][2]));
        out << ans.first << " " << ans.second << "\n";
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
