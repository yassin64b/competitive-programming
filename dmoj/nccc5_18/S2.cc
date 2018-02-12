#include <bits/stdc++.h>

using namespace std;

class nccc5s_2 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            in >> v[i];
        }
        int res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                res += v[j] > v[i];
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    nccc5s_2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
