#include <bits/stdc++.h>

using namespace std;

class A553 {
private:
    constexpr static int MOD = 1'000'000'007;
    vector<vector<int>> comp_ncr() {
        vector<vector<int>> ncr(1000 + 1, vector<int>(1000 + 1));
        for(int i = 0; i <= 1000; i++) {
            ncr[i][0] = 1;
        }
        for(int i = 1; i <= 1000; i++) {
            for(int j = 1; j <= 1000; j++) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
            }
        }
        return ncr;
    }
public:
    void solve(istream& in, ostream& out) {
        int k, n = 0;
        in >> k;
        vector<int> c(k);
        for (int i = 0; i < k; ++i) {
            in >> c[i];
            n += c[i];
        }
        vector<vector<int>> ncr(comp_ncr());
        int res = 1;
        for (int i = k - 1; i >= 0; --i) {
            // place 1 ball at last free spot
            // rest (c[i] - 1) balls on rest (n - 1) spots
            res = 1LL * res * ncr[n - 1][c[i] - 1] % MOD;
            n -= c[i];
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A553 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}