#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> poss(101, 1);
        for (int i = 0; i < n; ++i) {
            int r;
            in >> r;
            vector<int> cur(101, 0);
            for (int j = 0; j < r; ++j) {
                int x;
                in >> x;
                cur[x] = 1;
            }
            for (int j = 1; j <= 100; ++j) {
                poss[j] = poss[j] && cur[j];
            }
        }
        for (int j = 1; j <= 100; ++j) {
            if (poss[j]) {
                out << j << " ";
            }
        }
        out << "\n";
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
