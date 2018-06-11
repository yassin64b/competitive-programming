#include <bits/stdc++.h>

using namespace std;

class B110 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        for (int i = 0; i < n; ++i) {
            out << (char)(i % 4 + 'a');
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B110 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
