#include <bits/stdc++.h>

using namespace std;

class gcj_standing_ovation {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int s_max;
            string s;
            in >> s_max >> s;
            int add = 0, sum = 0;
            for (int i = 0; i <= s_max; ++i) {
                if (s[i] > '0') {
                    if (sum < i) {
                        add += i - sum;
                        sum = i;
                    }
                    sum += s[i] - '0';
                }
            }
            out << "Case #" << t << ": " << add << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_standing_ovation solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
