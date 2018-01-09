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

class A368 {
public:
    void solve(istream& in, ostream& out) {
        int n, d;
        in >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            in >> a[i];
        int m;
        in >> m;
        sort(a.begin(), a.end());
        int res = 0;
        for (int i = 0; i < n && i < m; ++i)
            res += a[i];
        res -= d * max(0, m - n);
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A368 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}