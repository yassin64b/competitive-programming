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

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        long long n, k;
        in >> n >> k;
        string s = to_string(n);
        
        int numzeros = 0;
        int remove = 0;
        for (int i = (int)s.size()-1; numzeros < k && i >= 0; --i) {
            if (s[i] != '0') {
                s.erase(i, 1);
                ++remove;
            } else {
                ++numzeros;
            }
        }
        
        //out << s << endl;
        if (s.size() == 0) {
            out << -1 << endl;
        } else if (s[0] == '0') {
            out << remove + s.size()-1 << endl;
        } else {
            out << remove << endl;
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
