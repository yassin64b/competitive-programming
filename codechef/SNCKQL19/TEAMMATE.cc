#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

class TEAMMATE {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<int> S(N);
            map<int, int> cnt;
            for (int i = 0; i < N; ++i) {
                in >> S[i];
                ++cnt[S[i]];
            }
            int carry = 0, res = 1;
            for (auto it = rbegin(cnt); it != rend(cnt); ++it) {
                int v = it->second;
                if (carry) {
                    carry = 0;
                    res = (1LL * res * v) % MOD; // carry with any current
                    --v;
                }
                if (v) {
                    if (v % 2 == 1) {
                        res = (1LL * res * v) % MOD; // choose carry
                        carry = 1;
                        --v;
                    }
                    for (int i = v - 1; i >= 1; i -= 2) {
                        res = (1LL * res * i) % MOD; // number of pairings
                    }
                }
            }
            out << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TEAMMATE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
