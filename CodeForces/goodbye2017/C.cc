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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, r;
        in >> n >> r;
        vector<int> x(n);
        for (int i = 0; i < n; ++i)
            in >> x[i];
        vector<double> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = 0. + r;
            for (int j = 0; j < i; ++j) {
                double x1 = x[i], x2 = x[j];
                double y2 = res[j];
                if ((x1-x2)*(x1-x2) <= 4*r*r) {
                    double low = res[j], high = res[j] + 2*r;
                    for (int k = 0; k < 100; ++k) {
                        double y1 = (low + high) / 2;
                        if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=4*r*r)
                            low = y1;
                        else
                            high = y1;
                    }
                    res[i] = max(res[i], (low + high) / 2);
                }
            }
        }
        out.precision(17);
        for (double y : res)
            out << fixed << y << " ";
        out << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
