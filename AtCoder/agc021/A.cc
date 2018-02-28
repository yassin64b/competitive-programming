#include <bits/stdc++.h>

using namespace std;

class agc021_a {
public:
    void solve(istream& in, ostream& out) {
        string N;
        in >> N;
        int res = 0;
        for (int i = 0; i < (int)N.size(); ++i) res += N[i] - '0';
        if (N[0] == '1') {
            int tmp = 0;
            for (int i = 1; i < (int)N.size(); ++i) tmp += 9;
            res = max(res, tmp);
        } else {
            int tmp = N[0] - '0' - 1;
            for (int i = 1; i < (int)N.size(); ++i) tmp += 9;
            res = max(res, tmp);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc021_a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
