#include <bits/stdc++.h>

using namespace std;

class ccc06s4 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        while (in >> n && n) {
            vector<vector<int>> v(n + 1, vector<int>(n + 1));
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    in >> v[i][j];
                }
            }
            int i = 0;
            for (int x = 1; x <= n; ++x) {
                for (int y = 1; y <= n; ++y) {
                    for (int z = 1; z <= n; ++z) {
                        if (v[x][v[y][z]] != v[v[x][y]][z]) {
                            goto no;
                        }
                    }
                }
            }
            for (int ii = 1; ii <= n; ++ii) {
                bool ok = true;
                for (int x = 1; ok && x <= n; ++x) {
                    ok = (v[x][ii] == x && v[ii][x] == x);
                }
                if (ok) {
                    i = ii;
                    break;
                }
            }
            if (!i) {
                goto no;
            }
            for (int x = 1; x <= n; ++x) {
                bool ok = false;
                for (int xx = 1; !ok && xx <= n; ++xx) {
                    ok = (v[x][xx] == i && v[xx][x] == i);
                }
                if (!ok) {
                    goto no;
                }
            }
            out << "yes\n";
            continue;
            no:
            out << "no\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    ccc06s4 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
