#include <bits/stdc++.h>

using namespace std;

class ADACOINS {
public:
    void solve(istream& in, ostream& out) {
        int N, Q;
        in >> N >> Q;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            in >> A[i];
        }
        constexpr int MX = 100'000;
        bitset<MX + 1> b;
        b[0] = 1;
        for (int i = 0; i < N; ++i) {
            b |= (b << A[i]);
        }
        vector<int> dp(MX + 1, 0);
        for (int i = 1; i <= MX; ++i) {
            dp[i] = b[i] + dp[i - 1];
        }
        for (int i = 0; i < Q; ++i) {
            int B, E;
            in >> B >> E;
            out << dp[E] - dp[B - 1] << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    ADACOINS solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
