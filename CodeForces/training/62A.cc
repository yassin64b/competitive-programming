#include <bits/stdc++.h>

using namespace std;

class A62 {
private:
    int test(int a, int b) {
        return a - 1 <= b && (b - 1) / 2 <= a;
    }
public:
    void solve(istream& in, ostream& out) {
        int al, ar, bl, br;
        in >> al >> ar >> bl >> br;
        out << (test(al, br) || test(ar, bl) ? "YES\n" : "NO\n");
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A62 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
