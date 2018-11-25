#include <bits/stdc++.h>

using namespace std;

class TaskA {
private:
    void dfs(int x, int y, vector<vector<int>> &v, int n) {
        v[x][y] = 2;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (x + i >= 1 && x + i <= n && y + j >= 1 && y + j <= n) {
                    if (v[x + i][y + j] == 0) {
                        dfs(x + i, y + j, v, n);
                    }
                }
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, ax, ay, bx, by, cx, cy;
        in >> n >> ax >> ay >> bx >> by >> cx >> cy;
        vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            v[ax][i] = v[i][ay] = 1;
            if (ax + i <= n && ay + i <= n) v[ax + i][ay + i] = 1;
            if (ax - i >= 1 && ay + i <= n) v[ax - i][ay + i] = 1;
            if (ax + i <= n && ay - i >= 1) v[ax + i][ay - i] = 1;
            if (ax - i >= 1 && ay - i >= 1) v[ax - i][ay - i] = 1;
        }
        dfs(bx, by, v, n);
        out << (v[cx][cy] == 2 ? "YES\n" : "NO\n");
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
