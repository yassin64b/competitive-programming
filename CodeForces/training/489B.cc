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

class B489 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        in >> m;
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            in >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0, res = 0;
        while (i < n && j < m) {
            if (abs(a[i] - b[j]) > 1) {
                if (b[j] > a[i]) {
                    ++i;
                } else {
                    ++j;
                }
            } else {
                ++res;
                ++i;
                ++j;
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    B489 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}