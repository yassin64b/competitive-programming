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

class A344 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        int res = 1, last = -1;
        for (int i = 0; i < n; ++i) {
            string s;
            in >> s;
            if (s == "01") {
                if (last == 0) {
                    ++res;
                }
                last = 1;
            } else {
                if (last == 1) {
                    ++res;
                }
                last = 0;
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A344 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
