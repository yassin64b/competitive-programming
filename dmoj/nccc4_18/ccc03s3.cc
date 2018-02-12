#include <bits/stdc++.h>

using namespace std;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};

class ccc03s3 {
private:
    int dfs(int i, int j, const vector<string> &p, vector<vector<bool>> &vis) {
        int res = 1;
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < (int)p.size() && nj >= 0 && nj < (int)p[0].size()) {
                if (p[ni][nj] == '.' && !vis[ni][nj]) {
                    res += dfs(ni, nj, p, vis);
                }
            }
        }
        return res;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, r, c;
        in >> n >> r >> c;
        vector<string> plan(r);
        for (int i = 0; i < r; ++i) {
            in >> plan[i];
        }
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        vector<int> room_sz;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (plan[i][j] == '.' && !vis[i][j]) {
                    room_sz.push_back(dfs(i, j, plan, vis));
                }
            }
        }
        sort(room_sz.begin(), room_sz.end());
        reverse(room_sz.begin(), room_sz.end());
        int num = 0;
        for (int x : room_sz) {
            if (x <= n) {
                n -= x;
                ++num;
            } else {
                break;
            }
        }
        out << num << (num == 1 ? " room, " : " rooms, ") << n << " square metre(s) left over\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    ccc03s3 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
