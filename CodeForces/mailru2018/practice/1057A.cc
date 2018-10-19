#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> p(n, -1);
        for (int i = 1; i < n; ++i) {
            in >> p[i];
        }
        vector<int> res;
        for (int i = n - 1; i >= 0; i = p[i] - 1) {
            res.push_back(i + 1);
        }
        reverse(begin(res), end(res));
        for (int x : res) {
            out << x << " ";
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
