#include <bits/stdc++.h>

using namespace std;

class gcj_deceitful_war {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<double> naomi(N), ken(N);
            for (int i = 0; i < N; ++i) {
                in >> naomi[i];
            }
            for (int i = 0; i < N; ++i) {
                in >> ken[i];
            }
            sort(begin(naomi), end(naomi));
            sort(begin(ken), end(ken));
            int y = 0, z = 0;
            // deceitful war
            for (int ni = 0, nj = N - 1, kj = N - 1; ni <= nj; ++ni) {
                // play heaviest as long as it will win
                while (ni <= nj && naomi[nj] > ken[kj]) {
                    ++y;
                    --nj;
                    --kj;
                }
                // then play lighest and make ken play heaviest
                --kj;
            }

            // war (naomi's order doesn't matter)
            for (int nj = N - 1, ki = 0, kj = N - 1; nj >= 0; --nj) {
                if (naomi[nj] > ken[kj]) { // naomi will win -> ken plays lighest
                    ++z;
                    ++ki;
                } else { // ken can play heaviest vs naomi's heaviest
                    --kj;
                }
            }
            
            out << "Case #" << t << ": " << y << " " << z << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_deceitful_war solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
