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

class timus1260 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        
        vector<int> dp(N+4);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < N; ++i) {
            dp[i] = dp[i-1] + dp[i-3] + dp[0];
        }
        /*for (int i = 0; i < N; ++i) {
            out << dp[i] << " ";
        }*/
        out << dp[N-1] << endl;
    
        /*//verify
        char c;
        cout << "verify? ";
        cin >> c;
        
        if (c == 'y') {
            vector<int> v(N);
            for (int i = 0; i < N; ++i) {
                v[i] = i+1;
            }
            int res = 1;
            while (next_permutation(v.begin()+1, v.end())) {
                bool flag = true;
                for (int i = 0; flag && i < N-1; ++i) {
                    if (abs(v[i] - v[i+1]) > 2) {
                        flag = false;
                    }
                }
                res += flag;
            }
            cout << "verify: " << res << endl;
        }*/
        
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    timus1260 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
