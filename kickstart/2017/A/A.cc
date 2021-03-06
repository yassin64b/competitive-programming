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

constexpr int MOD = 1000*1000*1000+7;

class A {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        
        for (int t = 1; t <= T; ++t) {
            int R, C;
            in >> R >> C;
            
            //cout << t << ": " << endl;
            long long res = 0;
            for (int len = 1; len <= min(R, C)-1; ++len) {
                long long mult = ((R-len) * (long long)(C-len)) % MOD;
                res = (res + mult * len) % MOD;
                //assert(res >= 0);
                //cout << mult << " " << len << " -> " << mult * len << endl;
                /*for (int i = 0; i < R-len; ++i) {
                    for (int j = 0; j < C-len; ++j) {
                        //cout << i << " " << j << " " << len << endl;
                        ++res;
                        res %= MOD;
                        res += len-1;
                        res %= MOD;
                    }
                }*/
            }
            out << "Case #" << t << ": " << res << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    A solver;
    std::istream& in(cin);
    std::ostream& out(cout);
    solver.solve(in, out);
    return 0;
}
