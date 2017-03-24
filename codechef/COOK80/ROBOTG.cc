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

class ROBOTG {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int n, m;
            string s;
            in >> n >> m >> s;
            int maxx = 0, maxy = 0, minx = 0, miny = 0, curx = 0, cury = 0;
            for (int i = 0; i < (int)s.size(); ++i) {
                switch (s[i]) {
                    case 'L':
                        --curx;
                        break;
                    case 'R':
                        ++curx;
                        break;
                    case 'U':
                        --cury;
                        break;
                    case 'D':
                        ++cury;
                        break;
                    default:
                        assert(true);
                        break;
                }
                maxx = max(maxx, curx);
                maxy = max(maxy, cury);
                minx = min(minx, curx);
                miny = min(miny, cury);
            }
            //cout << maxx << " " << minx << " " << maxy << " " << miny << endl;
            if (abs(maxx - minx) < m && abs(maxy - miny) < n) {
                out << "safe\n";
            } else {
                out << "unsafe\n";
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    ROBOTG solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}