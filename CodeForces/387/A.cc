/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin64b
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

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;

        int bb = 1000000, ba = 0;
        for (int b = 1; b <= n; ++b) {
            int a = n / b;
            if (a * b == n && a <= b && b - a < bb - ba) {
                bb = b;
                ba = a;
            }
        }

        out << ba << " " << bb << std::endl;
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
