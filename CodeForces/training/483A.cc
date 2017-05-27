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

class A483 {
public:
    void solve(istream& in, ostream& out) {
        long long l, r;
        in >> l >> r;
        if (l + 2 > r || ((l + 2) % 2 == 1 && l + 3 > r)) {
            out << -1 << "\n";
        } else {
            if (l % 2 == 0) {
                out << l << " " << l + 1 << " " << l + 2 << "\n";
            } else {
                out << l + 1 << " " << l + 2 << " " << l + 3 << "\n";
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A483 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}