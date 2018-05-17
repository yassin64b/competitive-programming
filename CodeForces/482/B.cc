#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        string s[3];
        in >> s[0] >> s[1] >> s[2];
        int m = s[0].size();
        map<char, int> cnt[3]{};
        for (int i = 0; i < 3; ++i) {
            cnt[i][0] = 0;
            for (char c : s[i]) {
                ++cnt[i][c];
            }
        }
        int mx = 0;
        set<int> v;
        for (int i = 0; i < 3; ++i) {
            for (auto [c, t] : cnt[i]) {
                int cur = min(m, t + n);
                if (n == 1 && t == m) {
                    cur = t - 1;
                }
                if (cur > mx) {
                    mx = cur;
                    v = {i};
                } else if (cur == mx) {
                    v.insert(i);
                }
            }
        }
        string name[3]{"Kuro", "Shiro", "Katie"};
        if (v.size() > 1U) {
            out << "Draw\n";
        } else {
            out << name[*v.begin()] << "\n";
        }
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
