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

class TaskC {
private:
    static constexpr int MOD = 1'000'000'007;
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> dp(5'001, 0);
        dp[0] = 1;
        bool last_f = false;
        for (int i = 0; i < N; ++i) {
            char c;
            in >> c;
            vector<int> nxt(5'001, 0);
            if (last_f) {
                for (int j = 0; j + 1 <= 5000; ++j) {
                    nxt[j + 1] = dp[j];
                }
            } else {
                int sum = 0;
                for (int j = 5000; j >= 0; --j) {
                    nxt[j] = sum = (sum + dp[j]) % MOD;
                }
            }
            last_f = (c == 'f');
            dp = nxt;
        }
        int res = 0;
        for (int x : dp) {
            res = (res + x) % MOD;
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
