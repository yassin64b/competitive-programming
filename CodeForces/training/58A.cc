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

class A58 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        int j = 0;
        string hello("hello");
        for (int i = 0; i < n; ++i) {
            if (j < (int)hello.size() && s[i] == hello[j]) {
                ++j;
            }
        }
        out << (j == (int)hello.size() ? "YES\n" : "NO\n");
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A58 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
