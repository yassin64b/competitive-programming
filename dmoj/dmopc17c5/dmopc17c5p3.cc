#include <bits/stdc++.h>

using namespace std;

class dmopc17c5p3 {
private:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    bool is_prime(long long x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (long long i = 3; i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            in >> A[i];
        }
        long long a_gcd = 0;
        for (long long x : A) {
            a_gcd = gcd(x, a_gcd);
        }
        if (is_prime(a_gcd)) {
            out << a_gcd << "\n";
            return;
        } else if (a_gcd == 1) {
            out << "DNE\n";
            return;
        }
        long long res = 1;
        if (a_gcd % 2 == 0) {
            res = 2;
            while (a_gcd % 2 == 0) a_gcd /= 2;
        }
        for (long long i = 3; i * i <= a_gcd; i += 2) {
            if (a_gcd % i == 0) {
                res = i;
                while (a_gcd % i == 0) a_gcd /= i;
            }
        }
        out << max(res, a_gcd) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmopc17c5p3 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
