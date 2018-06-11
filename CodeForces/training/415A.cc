#include <bits/stdc++.h>

using namespace std;

class A415 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        stack<int> s;
        for (int i = 1; i <= n; ++i) {
            s.push(i);
        }
        vector<int> res(n, 0);
        for (int i = 0; i < m; ++i) {
            int b;
            in >> b;
            while (!s.empty() && s.top() >= b) {
                res[s.top() - 1] = b;
                s.pop();
            }
        }
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A415 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
