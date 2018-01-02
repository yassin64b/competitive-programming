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

class A376 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int pivot = s.find('^');
        long long sum = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (isdigit(s[i]))
                sum += (i - pivot) * (s[i] - '0');
        }
        if (sum == 0) {
            out << "balance\n";
        } else if (sum < 0) {
            out << "left\n";
        } else {
            out << "right\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A376 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
