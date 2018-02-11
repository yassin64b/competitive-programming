#include <bits/stdc++.h>

using namespace std;

class yandex_A {
public:
    void solve(istream& in, ostream& out) {
        int h, m;
        in >> h >> m;
        if (h > 6) {
            int dist = 12 - h;
            h = dist;
        } else if (h > 0) {
            int dist = h;
            h = 12 - dist;
        }
        if (m > 30) {
            int dist = 60 - m;
            m = dist;
        } else if (m > 0) {
            int dist = m;
            m = 60 - dist;
        }
        out << h << " " << m << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    yandex_A solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
