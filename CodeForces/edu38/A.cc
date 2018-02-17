#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    bool isvowel(char c) {
        return "aeiouy"s.find(c) != string::npos;
    }
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        string res;
        res += s[0];
        for (int i = 1; i < n; ++i) {
            if (!(isvowel(s[i]) && isvowel(s[i - 1]))) {
                res += s[i];
            }
        }
        out << res << "\n";
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
