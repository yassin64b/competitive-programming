/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin64b
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

using namespace std;

class uva10684 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        while (in >> N && N) {
            vector<int> v(N), dp(N);
            for (int i = 0; i < N; ++i) {
                in >> v[i];
            }
            
            dp[0] = max(0, v[0]);
            int mx = dp[0];
            for (int i = 1; i < N; ++i) {
                dp[i] = max(v[i], v[i] + dp[i-1]);
                mx = max(mx, dp[i]);
            }
            
            if (mx == 0) {
                out << "Losing streak." << endl;
            } else {
                out << "The maximum winning streak is " << mx << "." << endl;
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    uva10684 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
