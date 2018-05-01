#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class agc023_a {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<i64> A(N);
        for (int i = 0; i < N; ++i) {
            in >> A[i];
        }
        i64 sum = 0, res = 0;
        map<i64, int> m;
        m[0] = 1;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            res += m[sum];
            ++m[sum];
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc023_a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
