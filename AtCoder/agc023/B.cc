#include <bits/stdc++.h>

using namespace std;

class agc023_b {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<string> S(N);
        for (int i = 0; i < N; ++i) {
            in >> S[i];
        }
        int res = 0;
        for (int b = 0; b < N; ++b) {
            bool ok = true;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (S[i][(j + b) % N] != S[j][(i + b) % N]) {
                        ok = false;
                    }
                }
            }
            res += ok * N;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc023_b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
