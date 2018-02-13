#include <bits/stdc++.h>

using namespace std;

class nccc3s4 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        long long sum = 0;
        vector<int> b(N);
        for (int i = 0; i < N; ++i) {
            in >> b[i];
            sum += b[i];
        }
        sort(b.begin(), b.end());
        if (sum % 2 == 0 && sum - b.back() >= b.back()) {
            out << "YES\n";
        } else {
            out << "NO\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    nccc3s4 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
