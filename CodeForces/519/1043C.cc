#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        vector<int> res(n, 0);
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i + 1] != s[i]) {
                res[i] = 1;
                reverse(begin(s), begin(s) + i + 1);
            }
        }
        if (s.back() == 'a') {
            res.back() = 1;
            reverse(begin(s), end(s));
        }
        for (int x : res) {
            out << x << " ";
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
