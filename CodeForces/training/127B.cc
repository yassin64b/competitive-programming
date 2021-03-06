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

using namespace std;

class B127 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            in >> a[i];
        map<int, int> m;
        for (int i = 0; i < n; ++i)
            ++m[a[i]];
        int res = 0;
        for (const auto& p : m) {
            int num = p.second;
            res += num / 2;
        }
        out << res / 2 << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B127 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
