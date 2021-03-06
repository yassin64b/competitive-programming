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

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, d;
        in >> n >> d;
        string s;
        in >> s;
        int res = 0;
        for (int i = 0; ; ) {
            int nxt = i;
            for (int j = 1; j <= d && i + j < n; ++j) {
                if (s[i + j] == '1')
                    nxt = i + j;
            }
            ++res;
            if (nxt == n - 1) {
                out << res << "\n";
                return;
            }
            if (nxt == i)
                break;
            i = nxt;
        }
        out << -1 << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
