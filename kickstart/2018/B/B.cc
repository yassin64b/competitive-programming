#include <bits/stdc++.h>

using namespace std;

class kickstart_sherlock_and_the_bit_strings {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, K;
            long long P;
            in >> N >> K >> P;
            --P;
            vector<int> A(K), B(K), C(K);
            for (int i = 0; i < K; ++i) {
                in >> A[i] >> B[i] >> C[i];
                --A[i];
                --B[i];
            }
            string res(N, '-');
            for (int i = 0; i < K; ++i) {
                res[A[i]] = '0' + C[i];
            }
            for (int i = N - 1; i >= 0; --i) {
                if (res[i] == '-') {
                    res[i] = '0' + (P % 2);
                    P /= 2;
                }
            }
            out << "Case #" << t << ": " << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    kickstart_sherlock_and_the_bit_strings solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
