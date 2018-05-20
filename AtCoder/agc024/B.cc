#include <bits/stdc++.h>

using namespace std;

class agc024b {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            in >> P[i];
        }
        map<int, int> m;
        int mx = 1;
        for (int i = 0; i < N; ++i) {
            if (m.count(P[i] - 1)) {
                m[P[i]] = m[P[i] - 1] + 1;
                mx = max(mx, m[P[i]]);
            } else {
                m[P[i]] = 1;
            }
        }
        out << N - mx << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc024b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
