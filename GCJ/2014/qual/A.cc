#include <bits/stdc++.h>

using namespace std;

class gcj_magic_trick {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int ans1, ans2;
            in >> ans1;
            int cards1[4][4], cards2[4][4];
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    in >> cards1[i][j];
                }
            }
            in >> ans2;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    in >> cards2[i][j];
                }
            }
            --ans1;
            --ans2;
            int cnt = 0, card = -1;
            for (int j2 = 0; j2 < 4; ++j2) {
                for (int j1 = 0; j1 < 4; ++j1) {
                    if (cards1[ans1][j1] == cards2[ans2][j2]) {
                        ++cnt;
                        card = cards1[ans1][j1];
                    }
                }
            }
            out << "Case #" << t << ": ";
            if (cnt == 0) {
                out << "Volunteer cheated!\n";
            } else if (cnt > 1) {
                out << "Bad magician!\n";
            } else {
                out << card << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_magic_trick solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
