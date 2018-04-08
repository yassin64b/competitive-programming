#include <bits/stdc++.h>

using namespace std;

class gcj_saving_the_universe_again {
private:
    int calc_damage(const string &P) {
        int dmg = 0, strength = 1;
        for (char c : P) {
            if (c == 'S') {
                dmg += strength;
            } else {
                strength *= 2;
            }
        }
        return dmg;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int D;
            string P;
            in >> D >> P;
            out << "Case #" << t << ": ";
            if (count(begin(P), end(P), 'S') > D) {
                out << "IMPOSSIBLE\n";
                continue;
            }
            int ans = 0, n = P.size();
            while (calc_damage(P) > D) {
                ++ans;
                for (int j = n - 1; j >= 1; --j) {
                    if (P[j] == 'S' && P[j - 1] == 'C') {
                        swap(P[j], P[j - 1]);
                        break;
                    }
                }
            }
            out << ans << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_saving_the_universe_again solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
