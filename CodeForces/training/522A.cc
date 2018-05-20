#include <bits/stdc++.h>

using namespace std;

class A522 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        map<string, int> len;
        len["polycarp"] = 1;
        int res = 1;
        for (int i = 0; i < n; ++i) {
            string name1, name2;
            in >> name1 >> name2 >> name2;
            transform(begin(name1), end(name1), begin(name1), ::tolower);
            transform(begin(name2), end(name2), begin(name2), ::tolower);
            len[name1] = len[name2] + 1;
            res = max(res, len[name1]);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A522 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
