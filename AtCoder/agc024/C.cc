#include <bits/stdc++.h>

using namespace std;

class agc024c {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            in >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            if (A[i] > i) {
                out << -1 << "\n";
                return;
            }
        }
        vector<int> X(N, 0);
        long long res = 0;
        int add = 0;
        for (int i = N - 1; i >= 0; --i, --add) {
            add = max(add, 0);
            X[i] += add;
            if (X[i] > A[i]) {
                out << -1 << "\n";
                return;
            } else if (X[i] < A[i]) {
                add = A[i];
                res += A[i];
                X[i] = A[i];
            }
        }
        if (add > 0) {
            out << -1 << "\n";
        } else {
            out << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc024c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
