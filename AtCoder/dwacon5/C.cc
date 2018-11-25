#include <bits/stdc++.h>

using namespace std;

class dwacon5_c {
public:
    void solve(istream& in, ostream& out) {
        int N, Q;
        string S;
        in >> N >> S >> Q;
        for (int i = 0; i < Q; ++i) {
            int k;
            in >> k;
            long long res = 0;
            long long d = 0, m = 0, dm = 0;
            for (int i = 0; i < N; ++i) {
                if (i >= k) {
                    int j = i - k;
                    /*if (S[j] == 'D') { // slower
                        dm -= m;
                        d -= 1;
                    } else if (S[j] == 'M') {
                        m -= 1;
                    }*/
                    dm -= m * (S[j] == 'D');
                    d -= 1 * (S[j] == 'D');
                    m -= 1 * (S[j] == 'M');
                }
                /*if (S[i] == 'D') { // slower
                    d += 1;
                } else if (S[i] == 'M') {
                    m += 1;
                    dm += d;
                } else if (S[i] == 'C') {
                    res += dm;
                }*/
                d += 1 * (S[i] == 'D');
                m += 1 * (S[i] == 'M');
                dm += d * (S[i] == 'M');
                res += dm * (S[i] == 'C');
            }
            out << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dwacon5_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
