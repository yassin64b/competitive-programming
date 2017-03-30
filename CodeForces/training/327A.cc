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

class A327 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        
        int res = 0;
        //O(n^3)
        /*for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int tmp = 0;
                for (int k = 0; k < n; ++k) {
                    if (k >= i && k <= j) {
                        tmp += 1 - a[k];
                    } else {
                        tmp += a[k];
                    }
                }
                res = max(res, tmp);
            }
        }*/
        //O(n)
        int sum = 0, mx = -1;
        for (int i = 0; i < n; ++i) {
            if (sum < 0) sum = 0;
            sum += (a[i] == 0 ? 1 : -1);
            mx = max(mx, sum);
        }
        res = accumulate(a.begin(), a.end(), 0) + mx;
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    A327 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}