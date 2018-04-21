#include <bits/stdc++.h>

using namespace std;

class gcj_bit_party {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int R, B, C;
            in >> R >> B >> C;
            vector<long long> M(C), S(C), P(C);
            for (int i = 0; i < C; ++i) {
                in >> M[i] >> S[i] >> P[i];
            }
            long long low_t = 0, high_t = 9'000'000'000'000'000'000, ans_t = high_t;
            while (low_t <= high_t) {
                long long mid_t = (low_t + high_t) / 2;
                vector<long long> num(C);
                for (int i = 0; i < C; ++i) {
                    num[i] = max(0LL, min((mid_t - P[i]) / S[i], M[i]));
                }
                sort(begin(num), end(num));
                reverse(begin(num), end(num));
                long long sum = 0;
                for (int i = 0; i < R; ++i) {
                    sum += num[i];
                }
                if (sum >= B) {
                    high_t = mid_t - 1;
                    ans_t = mid_t;
                } else {
                    low_t = mid_t + 1;
                }
            }
            out << "Case #" << t << ": " << ans_t << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_bit_party solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
