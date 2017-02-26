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

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> ac(5, 0), bc(5, 0);
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            ++ac[a[i] - 1];
        }
        for (int i = 0; i < n; ++i) {
            in >> b[i];
            ++bc[b[i]-1];
        }
        int diff = 0;
        for (int i = 0; i < 5; ++i) {
            if (abs(ac[i] - bc[i]) % 2 == 1) {
                out << -1 << "\n";
                return;
            }
            diff += abs(ac[i] - bc[i]);
        }
        if (diff % 4 == 0) {
            out << diff / 4 << "\n";
        } else {
            out << -1 << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}