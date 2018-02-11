#include <bits/stdc++.h>

using namespace std;

class yandex_B {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        string best;
        for (int i = 0; i < n; ++i) {
            if (i + 2 <= n && s[i] == s[i + 1]) {
                if (best == "" || best.size() > 2U || string() + s[i] + s[i + 1] < best) {
                    best = string() + s[i] + s[i + 1];
                }
            }
            if (i + 3 <= n && s[i] == s[i + 2] && best.size() != 2U) {
                if (best == "" || string() + s[i] + s[i + 1] + s[i + 2] < best) {
                    best = string() + s[i] + s[i + 1] + s[i + 2];
                }
            }
        }
        out << (best == "" ? "-1" : best) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    yandex_B solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
