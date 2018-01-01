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
#include <iomanip>

using namespace std;

class year2018p1 {
public:
    void solve(istream& in, ostream& out) {
        int h, m, s;
        in >> h >> m >> s;
        m += s / 60;
        s %= 60;
        h += m / 60;
        m %= 60;
        h %= 12;
        int hours, minutes, seconds;
        seconds = -s;
        if (seconds < 0) {
            seconds += 60;
            ++m;
        }
        minutes = -m;
        if (minutes < 0) {
            minutes += 60;
            ++h;
        }
        hours = 12 - h;
        if (hours < 0) {
            hours += 12;
        }
        out << setfill('0') << setw(2) << hours << ":";
        out << setfill('0') << setw(2) << minutes << ":";
        out << setfill('0') << setw(2) << seconds << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    year2018p1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
