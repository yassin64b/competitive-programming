#include <bits/stdc++.h>

using namespace std;

class nccc5s_1 {
public:
    void solve(istream& in, ostream& out) {
        int N, X;
        in >> N >> X;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            in >> a[i];
        }
        sort(a.begin(), a.end());
        int res = 0;
        for (int j = 0; j < N; ++j) {
            if (a[j] == X) {
                res += j * (N - j - 1);
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    nccc5s_1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
