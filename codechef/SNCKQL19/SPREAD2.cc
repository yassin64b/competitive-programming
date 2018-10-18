#include <bits/stdc++.h>

using namespace std;

class SPREAD2 {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<int> A(N);
            for (int i = 0; i < N; ++i) {
                in >> A[i];
            }
            int ans = 0;
            for (long long upto = 1, sum = A[0]; upto < N; ++ans) {
                long long bound = upto + sum;
                for (long long i = upto; i < bound && i < N; ++i) {
                    sum += A[i];
                }
                upto = bound;
            }
            out << ans << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    SPREAD2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
