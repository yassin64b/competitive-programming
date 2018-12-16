#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        vector<int> res(101, -1);
        res[0] = 0;
        for (int i = 1; i <= 100; ++i) {
            for (int j = 2; j <= 7; ++j) {
                if (i - j >= 0 && res[i - j] != -1) {
                    res[i] = res[i - j] + 1;
                }
            }
        }
        for (int t = 1; t <= T; ++t) {
            int x;
            in >> x;
            out << res[x] << "\n";
        }
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
