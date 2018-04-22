#include <bits/stdc++.h>

using namespace std;

class arc095_c {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<pair<int, int>> X(N);
        for (int i = 0; i < N; ++i) {
            in >> X[i].first;
            X[i].second = i;
        }
        sort(begin(X), end(X));
        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            if (i < N / 2) {
                B[X[i].second] = X[N / 2].first;
            } else {
                B[X[i].second] = X[N / 2 - 1].first;
            }
        }
        for (int y : B) {
            out << y << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc095_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
