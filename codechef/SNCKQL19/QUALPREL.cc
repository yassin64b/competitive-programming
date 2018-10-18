#include <bits/stdc++.h>

using namespace std;

class QUALPREL {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, K;
            in >> N >> K;
            vector<int> S(N);
            for (int i = 0; i < N; ++i) {
                in >> S[i];
            }
            sort(begin(S), end(S));
            reverse(begin(S), end(S));
            int ans = 0;
            for (int score : S) {
                ans += (score >= S[K - 1]);
            }
            out << ans << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    QUALPREL solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
