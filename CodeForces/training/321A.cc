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

class A321 {
public:
    void solve(istream& in, ostream& out) {
        int a, b;
        string s;
        in >> a >> b >> s;
        if (a == 0 && b == 0) {
            out << "Yes\n";
            return;
        }
        int x = 0, y = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'U') {
                ++y;
            } else if (s[i] == 'D') {
                --y;
            } else if (s[i] == 'L') {
                --x;
            } else {
                ++x;
            }
        }
        
        int xx = 0, yy = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'U') {
                ++yy;
            } else if (s[i] == 'D') {
                --yy;
            } else if (s[i] == 'L') {
                --xx;
            } else {
                ++xx;
            }
            int mul = 0;
            if (x) {
                mul = (a - xx) / x;
            } else if (y) {
                mul = (b - yy) / y;
            }
            if (mul >= 0 && x * mul == a - xx && y * mul == b - yy) {
                out << "Yes\n";
                return;
            }
        }
        out << "No\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A321 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
