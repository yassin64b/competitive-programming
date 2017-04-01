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

class A214 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        int res = 0;
        for (int a = 0; a <= 1000; ++a) {
            for (int b = 0; b <= 1000; ++b) {
                if (a*a + b == n && a + b*b == m) {
                    ++res;
                }
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A214 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
