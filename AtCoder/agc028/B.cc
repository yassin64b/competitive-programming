#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

// get modular inverse for prime MOD with call modPow(a, MOD - 2, MOD)
int modPow(int a, int b, int c = MOD){
    long long x = 1, y = a;
    while (b > 0){
        if (b % 2 == 1){
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b /= 2;
    }
    return x % c;
}

class agc028_b {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            in >> A[i];
        }
        vector<int> frac(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            frac[i] = modPow(i, MOD - 2);
            frac[i] = (frac[i] + frac[i - 1]) % MOD;
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) { // compute expected value
            int d1 = i + 1, d2 = N - i;
            ans = (ans + 1LL * (frac[d1] + frac[d2] - frac[1]) * A[i]) % MOD;
        }
        for (int i = 1; i <= N; ++i) { // multiply by n! to get sum
            ans = (1LL * ans * i) % MOD;
        }
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc028_b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
