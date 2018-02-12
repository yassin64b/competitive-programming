#include <bits/stdc++.h>

using namespace std;

class nccc5s4 {
public:
    void solve(istream& in, ostream& out) {
        int N, K;
        in >> N >> K;
        vector<int> a(K);
        for (int i = 0; i < K; ++i) {
            in >> a[i];
        }
        unsigned long long res = 0;
        for (int i = 0; i + 2 < K; ++i) {
            // substring that has first C at a[i] and third at a[i + 2]
            unsigned long long num1 = (i > 0 ? a[i] - a[i - 1] : a[i] - 0);
            unsigned long long num2 = N - a[i + 2] + 1;
            res += num1 * num2;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    nccc5s4 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
