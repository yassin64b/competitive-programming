#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        out << (n % 2 ? "Ehab" : "Mahmoud") << "\n";
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
