#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream &in, ostream &out) {
        int n;
        in >> n;
        string s;
        in >> s;
        if (s == "0") {
            out << "0\n";
            return;
        }
        int cnt0 = count(begin(s), end(s), '0');
        out << "1" << string(cnt0, '0') << "\n";
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
