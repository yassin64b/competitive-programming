#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

class CHEFPRMS {
public:
    void solve(istream& in, ostream& out) {
        vector<int> primes;
        for (int i = 2; i <= 200; ++i) {
            if (is_prime(i)) {
                primes.push_back(i);
            }
        }
        set<int> semi_primes;
        for (int a : primes) {
            for (int b : primes) {
                if (a != b && a * b <= 200) {
                    semi_primes.insert(a * b);
                }
            }
        }
        set<int> poss;
        for (int a : semi_primes) {
            for (int b : semi_primes) {
                if (a + b <= 200) {
                    poss.insert(a + b);
                }
            }
        }
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            out << (poss.count(N) ? "YES" : "NO") << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    CHEFPRMS solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
