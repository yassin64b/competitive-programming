#include <bits/stdc++.h>

using namespace std;

class A471 {
public:
    void solve(istream& in, ostream& out) {
        int l[6];
        for (int i = 0; i < 6; ++i) {
            in >> l[i];
        }
        sort(begin(l), end(l));
        for (int i = 0; i + 4 <= 6; ++i) {
            bool ok = true;
            for (int j = i + 1; ok && j < i + 4; ++j) {
                ok = (l[j] == l[j - 1]);
            }
            if (ok) {
                int a = l[(i + 4) % 6], b = l[(i + 5) % 6];
                if (a != b) {
                    out << "Bear\n";
                } else {
                    out << "Elephant\n";
                }
                return;
            }
        }
        out << "Alien\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A471 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
