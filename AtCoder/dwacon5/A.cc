#include <bits/stdc++.h>

using namespace std;

class dwacon5_a {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            in >> a[i];
        }
        int sum = accumulate(begin(a), end(a), 0);
        double avg = sum / (double)N;
        int i = 0;
        for (int j = 1; j < N; ++j) {
            if (abs(a[j] - avg) < abs(a[i] - avg)) {
                i = j;
            }
        }
        out << i << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dwacon5_a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
