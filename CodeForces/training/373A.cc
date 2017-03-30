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

class A373 {
public:
    void solve(istream& in, ostream& out) {
        int k;
        in >> k;
        char g[4][4];
        int cnt[10]{};
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                in >> g[i][j];
                if (g[i][j] >= '0' && g[i][j] <= '9') {
                    ++cnt[g[i][j]-'0'];
                    if (cnt[g[i][j]-'0'] > 2*k) {
                        out << "NO\n";
                        return;
                    }
                }
            }
        }
        out << "YES\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A373 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
