#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> p(n / 2);
        for (int i = 0; i < n / 2; ++i) {
            in >> p[i];
        }
        sort(begin(p), end(p));
        int res1 = 0, res2 = 0;
        for (int i = 0; i < n / 2; ++i) {
            res1 += abs(p[i] - (2 * i + 1));
            res2 += abs(p[i] - (2 * i + 2));
        }
        out << min(res1, res2) << "\n";
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
