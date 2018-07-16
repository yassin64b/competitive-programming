#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int b = 0, c = 0;
        int n = s.size();
        string res;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++c;
            } else if (s[i] == '1') {
                ++b;
            } else {
                while (c) res.push_back('0'), --c;
                res.push_back('2');
            }
        }
        while (b) res.push_back('1'), --b;
        while (c) res.push_back('0'), --c;
        reverse(begin(res), end(res));
        out << res << "\n";
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
