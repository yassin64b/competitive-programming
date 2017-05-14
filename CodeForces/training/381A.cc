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

class A381 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            in >> v[i];
        }
        int i = 0, j = n-1;
        int sum[2]{0, 0}, turn = 0;
        while (i <= j) {
            if (v[i] > v[j]) {
                sum[turn] += v[i];
                ++i;
            } else {
                sum[turn] += v[j];
                --j;
            }
            turn = 1 - turn;
        }
        
        out << sum[0] << " " << sum[1] << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A381 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
