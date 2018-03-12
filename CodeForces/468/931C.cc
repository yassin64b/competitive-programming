#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            in >> x[i];
        }
        int mn = *min_element(begin(x), end(x));
        int sum_x = 0, a_x = 0, b_x = 0, c_x = 0;
        // a: number of zeroes, b: num 1s, c: num 2s
        for (int i = 0; i < n; ++i) {
            x[i] -= mn;
            a_x += x[i] == 0;
            b_x += x[i] == 1;
            c_x += x[i] == 2;
            sum_x += x[i];
        }
        if (c_x == 0) {
            out << n << "\n";
            for (int z : x) {
                out << z + mn << " ";
            }
            out << "\n";
            return;
        }
        int best_strike_off = n + 1, best_a_y = -1, best_b_y = -1, best_c_y = -1;
        vector<int> y(n);
        for (int c_y = 0; c_y <= n; ++c_y) {
            int b_y = sum_x - 2 * c_y;
            if (b_y >= 0 && b_y + c_y <= n) {
                int a_y = n - (b_y + c_y);
                int strike_off = n - (max(0, a_y - a_x) + max(0, b_y - b_x) + max(0, c_y - c_x));
                if (strike_off < best_strike_off) {
                    best_strike_off = strike_off;
                    best_a_y = a_y;
                    best_b_y = b_y;
                    best_c_y = c_y;
                }
            }
        }
        assert(best_a_y + best_b_y + best_c_y == n);
        for (int i = 0; i < best_a_y; ++i) y[i] = 0 + mn;
        for (int i = best_a_y; i < best_a_y + best_b_y; ++i) y[i] = 1 + mn;
        for (int i = best_a_y + best_b_y; i < n; ++i) y[i] = 2 + mn;
        out << best_strike_off << "\n";
        for (int z : y) {
            out << z << " ";
        }
        out << "\n";
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
