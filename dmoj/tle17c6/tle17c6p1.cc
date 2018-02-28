#include <bits/stdc++.h>

using namespace std;

class tle17c6p1 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        string s;
        in >> s;
        int cnt[26]{};
        for (char c : s) ++cnt[c - 'a'];
        sort(cnt, cnt + 26);
        reverse(cnt, cnt + 26);
        if (cnt[0] <= n / 2 && n % 2 == 0) {
            out << "Yes\n";
        } else {
            out << "No\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    tle17c6p1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
