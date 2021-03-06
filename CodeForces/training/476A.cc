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

class A476 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        
        int num2 = n / 2, num1 = n % 2;
        while ((num2 + num1) % m != 0) {
            if (num2 == 0) {
                out << "-1\n";
                return;
            }
            --num2;
            num1 += 2;
        }
        out << num2 + num1 << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    A476 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
