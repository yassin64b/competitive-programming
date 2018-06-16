#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int a, b, c, d;
        in >> a >> b >> c >> d;
        constexpr int n = 50;
        vector<string> res(50, string(50, ' '));
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                res[i][j] = 'A';
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            for (int j = n / 2; j < n; ++j) {
                res[i][j] = 'B';
            }
        }
        for (int i = n / 2; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                res[i][j] = 'C';
            }
        }
        for (int i = n / 2; i < n; ++i) {
            for (int j = n / 2; j < n; ++j) {
                res[i][j] = 'D';
            }
        }
        --a; --b; --c; --d;
        for (int i = 1; b && i + 1 < n / 2; i += 2) {
            for (int j = 1; b && j + 1 < n / 2; j += 2) {
                res[i][j] = 'B';
                --b;
            }
        }
        for (int i = 1; a && i + 1 < n / 2; i += 2) {
            for (int j = n / 2 + 1; a && j + 1 < n; j += 2) {
                res[i][j] = 'A';
                --a;
            }
        }
        for (int i = n / 2 + 1; d && i + 1 < n; i += 2) {
            for (int j = 1; d && j + 1 < n / 2; j += 2) {
                res[i][j] = 'D';
                --d;
            }
        }
        for (int i = n / 2 + 1; c && i + 1 < n; i += 2) {
            for (int j = n / 2 + 1; c && j + 1 < n; j += 2) {
                res[i][j] = 'C';
                --c;
            }
        }
        out << n << " " << n << "\n";
        for (const auto &s : res) {
            out << s << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
