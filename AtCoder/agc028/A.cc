#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

class agc028_a {
public:
    void solve(istream& in, ostream& out) {
        int N, M;
        in >> N >> M;
        string S, T;
        in >> S >> T;
        for (int a = 1; a <= M; ++a) {
            long long len = 1LL * a * N;
            if (len % M == 0) {
                long long b = len / M;
                long long t = lcm(a, b);
                bool ok = true;
                for (long long i = 0; ok && i < len; i += t) {
                    if (i / a >= N || i / b >= M) {
                        ok = false;
                    } else if (S[i / a] != T[i / b]) {
                        ok = false;
                    }
                }
                if (ok) {
                    out << len << "\n";
                    return;
                }
            }
        }
        out << -1 << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc028_a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
