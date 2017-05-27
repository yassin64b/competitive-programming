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

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        
        vector<int> last(n, -1), first(n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i] == a[j]) {
                    first[i] = min(first[i], j);
                    last[i] = max(last[i], j);
                }
            }
        }
        
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int last_ind = i, first_ind = i, best = 0, cur = 0;
            vector<int> seen(5000 + 1, 0);
            for (int j = i; j < n; ++j) {
                last_ind = max(last_ind, last[j]);
                first_ind = min(first_ind, first[j]);
                if (seen[a[j]] == 0) {
                    seen[a[j]] = 1;
                    cur ^= a[j];
                }
                if (first_ind >= i && last_ind <= j) {
                    best = cur;
                }
                dp[j] = max(dp[j], best + (i - 1 >= 0 ? dp[i - 1] : 0));
            }
        }
        out << dp[n - 1] << "\n";
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
