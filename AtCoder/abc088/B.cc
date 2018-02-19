#include <bits/stdc++.h>

using namespace std;

class abc088_b {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            in >> a[i];
        }
        sort(begin(a), end(a), greater<int>());
        int bal = 0;
        for (int i = 0; i < N; ++i) {
            bal += ((i % 2) ? -a[i] : a[i]);
        }
        out << bal << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    abc088_b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
