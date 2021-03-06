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

class A454 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        
        for (int i = 0; i <= n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j >= n / 2  - i && j <= n / 2 + i) {
                    out << "D";
                } else {
                    out << "*";
                }
            }
            out << "\n";
        }
        for (int i = n / 2 + 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j >= n / 2 - (n - i - 1) && j <= n / 2 + (n - i - 1)) {
                    out << "D";
                } else {
                    out << "*";
                }
            }
            out << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A454 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
