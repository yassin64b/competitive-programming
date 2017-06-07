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

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n), b(k);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < k; ++i) {
            in >> b[i];
        }
        sort(b.begin(), b.end(), greater<int>());
        for (int i = 0, j = 0; i < n; ++i) {
            if (a[i] == 0) {
                a[i] = b[j];
                ++j;
            }
        }
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] >= a[i + 1]) {
                out << "Yes\n";
                return;
            }
        }
        out << "No\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
