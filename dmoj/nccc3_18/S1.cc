#include <bits/stdc++.h>

using namespace std;

class nccc3j3s1 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int cnt[26]{};
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        sort(begin(cnt), end(cnt));
        reverse(begin(cnt), end(cnt));
        out << accumulate(begin(cnt) + 2, end(cnt), 0) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    nccc3j3s1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
