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

class G802 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        string heidi("heidi");
        int n = s.size(), m = heidi.size();
        for (int i = 0, j = 0; i < n; ++i) {
            if (s[i] == heidi[j]) {
                ++j;
                if (j == m) {
                    out << "YES\n";
                    return;
                }
            }
        }
        out << "NO\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    G802 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}