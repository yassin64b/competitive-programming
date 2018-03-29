#include <bits/stdc++.h>

using namespace std;

class arc093_d {
public:
    void solve(istream& in, ostream& out) {
        int a, b;
        in >> a >> b;
        int h = 100, w = h;
        vector<string> grid(h, string(w, '.'));
        for (int i = h / 2; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                grid[i][j] = '#';
            }
        }
        for (int i = 0; i < h / 2; i += 2) {
            for (int j = 0; j < w; j += 2) {
                if (b > 1) {
                    grid[i][j] = '#';
                    --b;
                }
            }
        }
        for (int i = h / 2 + 1; i < h; i += 2) {
            for (int j = 0; j < w; j += 2) {
                if (a > 1) {
                    grid[i][j] = '.';
                    --a;
                }
            }
        }
        out << h << " " << w << "\n";
        for (const string &s : grid) {
            out << s << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc093_d solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
