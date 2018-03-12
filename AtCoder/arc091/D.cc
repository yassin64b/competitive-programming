#include <bits/stdc++.h>

using namespace std;

class arc091_b {
public:
    void solve(istream& in, ostream& out) {
        int N, K;
        in >> N >> K;
        long long res = 0;
        for (int b = K + 1; b <= N; ++b) {
            for (int a = max(K, 1); a <= N; a += b) {
                if (a + b - K <= N)
                    res += b - K;
                else
                    res += N - a + 1;
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc091_b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
