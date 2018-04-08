#include <bits/stdc++.h>

using namespace std;

class B374 {
public:
    void solve(istream& in, ostream& out) {
        string a;
        in >> a;
        for (char &c : a) {
            c -= '0';
        }
        int n = a.size();
        vector<int> dp(n + 1, 0); // number of 9s possible up to i
        vector<long long> num(n + 1, 1); // number of ways to get dp1[i]
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            num[i] = num[i - 1];
            if (i - 2 >= 0 && a[i - 1] + a[i - 2] == 9) {
                if (dp[i - 2] + 1 > dp[i]) {
                    dp[i] = dp[i - 2] + 1;
                    num[i] = num[i - 2];
                } else if (dp[i - 2] + 1 == dp[i]) {
                    num[i] += num[i - 2];
                }
            }
        }
        out << num[n] << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B374 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
