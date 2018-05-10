#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<vector<char>> res(4, vector<char>(n, '.'));
        if (k % 2 == 1) {
            res[1][n / 2] = '#';
            --k;
        }
        for (int i = 1; i <= 2; ++i) {
            for (int a = 1, b = n - 2; a < b && k; k -= 2, ++a, --b) {
                res[i][a] = res[i][b] = '#';
            }
        }
        if (k) {
            res[1][n / 2] = res[2][n / 2] = '#';
        }
        out << "YES\n";
        for (const auto &v : res) {
            for (char c : v) {
                out << c;
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
