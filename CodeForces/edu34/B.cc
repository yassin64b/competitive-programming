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

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int h1, a1, c1;
        in >> h1 >> a1 >> c1;
        int h2, a2;
        in >> h2 >> a2;
        vector<string> res;
        while (true) {
            if (h2 - a1 <= 0) {
                res.push_back("STRIKE");
                break;
            } else if (h1 - a2 <= 0) {
                res.push_back("HEAL");
                h1 += c1;
            } else {
                res.push_back("STRIKE");
                h2 -= a1;
            }
            h1 -= a2;
        }
        out << res.size() << "\n";
        for (const string& s : res)
            out << s << "\n";
        
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
