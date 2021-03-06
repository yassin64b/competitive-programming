/*
ID: yassin.2
PROG: numtri
LANG: C++11
*/
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

class numtri {
public:
    void solve(istream& in, ostream& out) {
        int R;
        in >> R;
        
        vector<vector<int>> v(R);
        for (int r = 0; r < R; ++r) {
            v[r].resize(r+1);
            for (int i = 0; i <= r; ++i) {
                in >> v[r][i];
            }
        }
        
        for (int r = 1; r < R; ++r) {
            for (int i = 0; i <= r; ++i) {
                v[r][i] = max((i > 0 ? v[r-1][i-1] : 0), (i < r ? v[r-1][i] : 0)) + v[r][i];
            }
        }
        
        int mx = 0;
        for (int i = 0; i < R; ++i) {
            mx = max(mx, v[R-1][i]);
        }
        out << mx << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    numtri solver;
    std::ifstream in("numtri.in");
    std::ofstream out("numtri.out");
    solver.solve(in, out);
    return 0;
}
