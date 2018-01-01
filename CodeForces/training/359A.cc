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

class A359 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                in >> a[i][j];
        int mn = 4;
        for (int i = 0; i < n; ++i) {
            if (a[i][0] || a[i][m-1])
                mn = min(mn, 2);
        }
        for (int j = 0; j < m; ++j) {
            if (a[0][j] || a[n-1][j])
                mn = min(mn, 2);
        }
        out << mn << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A359 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
