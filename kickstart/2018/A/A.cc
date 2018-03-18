#include <bits/stdc++.h>

using namespace std;

class kickstart_even_digits {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            long long N;
            in >> N;
            string s(to_string(N));
            string a(s), b(s);
            bool ma = false, mb = false;
            bool oka = true;
            for (int i = 0; i < (int)s.size(); ++i) {
                int dig = s[i] - '0';
                if (ma) {
                    a[i] = '0';
                } else if (dig % 2) {
                    if (dig != 9) {
                        ma = true;
                        ++a[i];
                    } else {
                        oka = false;
                    }
                }
                if (mb) {
                    b[i] = '8';
                } else if (dig % 2) {
                    --b[i];
                    mb = true;
                }
            }
            out << "Case #" << t << ": ";
            long long na = stoll(a), nb = stoll(b);
            if (oka && abs(na - N) < abs(nb - N)) {
                out << abs(na - N);
            } else {
                out << abs(nb - N);
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    kickstart_even_digits solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
