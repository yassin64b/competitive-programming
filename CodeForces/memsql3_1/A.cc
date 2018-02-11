#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int K;
        in >> K;
        vector<int> r(K);
        for (int i = 0; i < K; ++i) {
            in >> r[i];
        }
        int mx_rk = *max_element(r.begin(), r.end());
        out << max(mx_rk - 25, 0) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
