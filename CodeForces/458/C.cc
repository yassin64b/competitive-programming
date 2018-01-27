/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <queue>
#include <functional>
#include <stack>
#include <numeric>
#include <cassert>
#include <sstream>

using namespace std;

constexpr int MOD = 1'000'000'007;

class TaskC {
private:
    vector<vector<int>> ncr;
    /*map<pair<long long, long long>, long long> ncr;
    long long choose(long long n, long long k) {
        if (ncr.count({n, k})) {
            return ncr[{n, k}];
        } else if (k == 0) {
            return 1;
        } else {
            return ncr[{n, k}] = (n * choose(n - 1, k - 1)) % MOD * inv(k, MOD) % MOD;
        }
    }*/
    void comp_ncr() {
        ncr.assign(1000 + 1, vector<int>(1000 + 1));
        for(int i = 0; i <= 1000; i++) {
            ncr[i][0] = 1;
        }
        for(int i = 1; i <= 1000; i++) {
            for(int j = 1; j <= 1000; j++) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
            }
        }
    }
    long long inv(long long a, long long b){
        return (1 < a) ? b - inv(b % a, a) * b / a : 1;
    }
    long long f(const string &s, int k, int num = 0) {
        if (k == 0) {
            return 1;
        }
        int m;
        int skip = num;
        for (m = 0; m < (int)s.size(); ++m) {
            if (s[m] == '1') {
                --skip;
                if (skip < 0) {
                    break;
                }
            }
        }
        if (m == (int)s.size()) {
            return 0;
        }
        m = (int)s.size() - m;
        long long tmp = f(s, k - 1, num + 1);
        return (ncr[m - 1][k] + tmp) % MOD;
    }
public:
    void solve(istream& in, ostream& out) {
        comp_ncr();
        string s;
        int k;
        in >> s >> k;
        if (k == 0) {
            out << 1 << "\n";
            return;
        }
        int m = s.size();
        vector<int> dp(m + 1);
        dp[1] = 1;
        for (int i = 2; i <= m; ++i) {
            int num = __builtin_popcount(i);
            dp[i] = dp[num] + 1;
        }
        long long res = 0;
        for (int i = 1; i <= m; ++i) {
            if (dp[i] == k) {
                res += f(s, i);
                if (i == 1) {
                    --res;
                }
                res %= MOD;
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
