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
        int a, b, c;
        in >> a >> b >> c;
        set<int> seen;
        int res = 1;
        a *= 10;
        while (seen.find(a) == seen.end()) {
            seen.insert(a);
            if (b <= a) {
                int nxtdig = a / b;
                a -= nxtdig * b;
                if (nxtdig == c) {
                    out << res << "\n";
                    return;
                }
                //cout << nxtdig << endl;
            } else {
                int nxtdig = 0;
                if (nxtdig == c) {
                    out << res << "\n";
                    return;
                }
                //cout << nxtdig << endl;
            }
            a *= 10;
            ++res;
        }
        out << -1 << "\n";
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
