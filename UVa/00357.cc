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
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vii;

constexpr int MAXV = 30000;
constexpr int coins[5] = {1, 5, 10, 25, 50};

class uva357 {
public:
    void solve(istream& in, ostream& out) {
        vector<vector<int64_t>> dp(MAXV+1, vector<int64_t>(5, 0));
        for (int j = 0; j < 5; ++j) {
            dp[0][j] = 1;
        }
        
        for (int i = 1; i <= MAXV; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (j > 0) dp[i][j] += dp[i][j-1];
                if (i - coins[j] >= 0) dp[i][j] += dp[i-coins[j]][j];
            }
        }
        
        int q;
        while (in >> q) {
            if (dp[q][4] == 1) {
                out << "There is only 1 way to produce " << q << " cents change.\n";
            } else {
                out << "There are " << dp[q][4] << " ways to produce " << q << " cents change.\n";
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    uva357 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}