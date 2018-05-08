#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        int mx = 0;
        int cnt[26][26]{};
        char c1 = 0, c2 = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (++cnt[s[i] - 'A'][s[i + 1] - 'A'] > mx) {
                c1 = s[i];
                c2 = s[i + 1];
                mx = cnt[c1 - 'A'][c2 - 'A'];
            }
        }
        out << c1 << c2 << "\n";
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
