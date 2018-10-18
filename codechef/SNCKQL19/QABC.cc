#include <bits/stdc++.h>

using namespace std;

class QABC {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<int> A(N), B(N);
            for (int i = 0; i < N; ++i) {
                in >> A[i];
            }
            for (int i = 0; i < N; ++i) {
                in >> B[i];
            }
            for (int i = 0; i < N - 2; ++i) {
                int diff = max(0, B[i] - A[i]);
                A[i] += diff;
                A[i + 1] += 2 * diff;
                A[i + 2] += 3 * diff;
            }
            bool ok = true;
            for (int i = 0; ok && i < N; ++i) {
                ok = (A[i] == B[i]);
            }
            out << (ok ? "TAK" : "NIE") << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    QABC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
