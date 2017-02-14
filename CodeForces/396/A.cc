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
        string a, b;
        in >> a >> b;
    
        if (a.size() != b.size()) {
            out << max(a.size(), b.size()) << "\n";
            return;
        }
        
        if (a == b) {
            out << "-1\n";
            return;
        } else {
            out << a.size() << "\n";
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
