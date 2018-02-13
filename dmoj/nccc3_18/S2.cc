#include <bits/stdc++.h>

using namespace std;

class nccc3j4s2 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> median(N);
        for (int i = 0; i < N; ++i) {
            vector<int> cur(N);
            for (int j = 0; j < N; ++j) {
                in >> cur[j];
            }
            sort(begin(cur), end(cur));
            median[i] = cur[N / 2];
        }
        sort(begin(median), end(median));
        out << median[N / 2] << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    nccc3j4s2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
