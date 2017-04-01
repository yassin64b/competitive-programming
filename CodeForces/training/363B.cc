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

class B363 {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            in >> h[i];
        }
        int cur_height = 0, mn_height, ind = 0;
        for (int i = 0; i < k; ++i) {
            cur_height += h[i];
        }
        mn_height = cur_height;
        for (int i = k; i < n; ++i) {
            cur_height -= h[i-k];
            cur_height += h[i];
            if (cur_height < mn_height) {
                mn_height = cur_height;
                ind = i-k+1;
            }
        }
        out << ind+1 << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    B363 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
