#include <bits/stdc++.h>

using namespace std;

class arc093_c {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> A(N + 1);
        A[0] = 0;
        for (int i = 0; i < N; ++i) {
            in >> A[i + 1];
        }
        ++N;
        vector<int> sufa(N + 1);
        sufa[N] = 0;
        sufa[N - 1] = abs(A[N - 1] - A[0]);
        for (int i = N - 2; i >= 0; --i) {
            sufa[i] = sufa[i + 1] + abs(A[i] - A[i + 1]);
        }
        int cur = 0;
        for (int i = 1; i < N; ++i) { // skip i
            out << cur + abs(A[i - 1] - A[(i + 1) % N]) + sufa[i + 1] << "\n";
            cur += abs(A[i - 1] - A[i]);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc093_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
