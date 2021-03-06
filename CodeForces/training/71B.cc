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

class B71 {
public:
    void solve(istream& in, ostream& out) {
        int n, k, t;
        in >> n >> k >> t;
        vector<int> a(n, 0);
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((sum + k) / (n * k) > t / 100.) {
                for (int j = 1; j <= k; ++j) {
                    if ((sum + j) / (n * k) > t / 100.) {
                        a[i] = j - 1;
                        break;
                    }
                }
                break;
            } else {
                a[i] = k;
                sum += a[i];
            }
        }
        for (int x : a)
            out << x << " ";
        out << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B71 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
