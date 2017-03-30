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

class B389 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c;
                in >> c;
                g[i][j] = (c == '#');
            }
        }
        
        for (int i = 1; i < n-1; ++i) {
            for (int j = 1; j < n-1; ++j) {
                if (g[i][j] && g[i-1][j] && g[i+1][j] && g[i][j-1] && g[i][j+1]) {
                    g[i][j] = g[i-1][j] = g[i+1][j] = g[i][j-1] = g[i][j+1] = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j]) {
                    out << "NO\n";
                    return;
                }
            }
        }
        out << "YES\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    B389 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
