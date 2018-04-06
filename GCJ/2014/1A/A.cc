#include <bits/stdc++.h>

using namespace std;

class gcj_charging_chaos {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, L;
            in >> N >> L;
            vector<string> a(N), b(N);
            for (int i = 0; i < N; ++i) {
                in >> a[i];
            }
            unordered_multiset<string> sb;
            for (int i = 0; i < N; ++i) {
                in >> b[i];
                sb.insert(b[i]);
            }
            int ans = -1;
            for (int i = 0; i < N; ++i) { // a[0] will fit to b[i]
                int cur = 0;
                vector<bool> change(L, false);
                for (int j = 0; j < L; ++j) {
                    change[j] = (a[0][j] != b[i][j]);
                    cur += change[j];
                }
                unordered_multiset<string> sa;
                for (int k = 0; k < N; ++k) {
                    string s = a[k];
                    for (int j = 0; j < L; ++j) {
                        if (change[j]) {
                            s[j] = (s[j] == '1' ? '0' : '1');
                        }
                    }
                    sa.insert(s);
                }
                if (sa == sb) {
                    if (ans == -1) {
                        ans = cur;
                    }
                    ans = min(ans, cur);
                }
            }
            out << "Case #" << t << ": ";
            if (ans == -1) {
                out << "NOT POSSIBLE\n";
            } else {
                out << ans << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_charging_chaos solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
