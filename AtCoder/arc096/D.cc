#include <bits/stdc++.h>

using namespace std;

class arc096_d {
public:
    void solve(istream& in, ostream& out) {
        int N;
        long long C;
        in >> N >> C;
        vector<long long> x(N), v(N);
        for (int i = 0; i < N; ++i) {
            in >> x[i] >> v[i];
        }
        vector<long long> dp1(N), dp2(N);
        long long cur = 0;
        for (int i = 0; i < N; ++i) {
            cur += v[i];
            dp1[i] = max((i > 0 ? dp1[i - 1] : 0), cur - x[i]);
        }
        
        vector<long long> x2(N);
        for (int i = 0; i < N; ++i) {
            x2[i] = C - x[i];
        }
        cur = 0;
        for (int i = N - 1; i >= 0; --i) {
            cur += v[i];
            dp2[i] = max((i < N - 1 ? dp2[i + 1] : 0), cur - x2[i]);
        }
        
        long long ans = max(dp2[0], dp1[N - 1]);
        for (int i = 0; i + 1 < N; ++i) {
            ans = max(ans, dp1[i] + dp2[i + 1] - min(x[i], x2[i + 1]));
        }
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc096_d solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
