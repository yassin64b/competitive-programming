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

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            ++m[a[i]];
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        bool win = false;
        for (int i = 0, cnt = 0; i < n; ++i) {
            cnt += m[a[i]];
            m[a[i]] = 0;
            if (cnt % 2 == 1) {
                win = true;
            }
        }
        out << (win ? "Conan" : "Agasa") << "\n";
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
