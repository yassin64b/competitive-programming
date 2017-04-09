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

class arcC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> v(26, 1000);
        for (int i = 0; i < n; ++i) {
            string s;
            in >> s;
            for (int j = 0; j <= 25; ++j) {
                v[j] = min(v[j], (int)std::count(s.begin(), s.end(), (char)('a'+j)));
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < v[i]; ++j) {
                out << (char)('a'+i);
            }
        }
        out << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    arcC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
