#include <bits/stdc++.h>

using namespace std;

class abc088_d {
public:
    void solve(istream& in, ostream& out) {
        int H, W;
        in >> H >> W;
        vector<string> grid(H);
        for (int i = 0; i < H; ++i) {
            in >> grid[i];
        }
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vector<vector<int>> dist(H, vector<int>(W, -1));
        dist[0][0] = 1;
        int dirx[4]{1, -1, 0, 0}, diry[4]{0, 0, 1, -1};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirx[i], ny = y + diry[i];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && dist[nx][ny] == -1
                        && grid[nx][ny] == '.')
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
        if (dist[H - 1][W - 1] == -1) {
            out << -1 << "\n";
        } else {
            int num_white = 0;
            for (int i = 0; i < H; ++i) {
                num_white += count(begin(grid[i]), end(grid[i]), '.');
            }
            assert(num_white >= dist[H - 1][W - 1]);
            out << num_white - dist[H - 1][W - 1] << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    abc088_d solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
