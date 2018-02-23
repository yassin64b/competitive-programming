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
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int stage = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (stage == 0) {
                if (a[i] == a[i + 1]) {
                    stage = 1;
                } else if (a[i] > a[i + 1]) {
                    stage = 2;
                }
            } else if (stage == 1) {
                if (a[i] > a[i + 1]) {
                    stage = 2;
                } else if (a[i] < a[i + 1]) {
                    out << "NO\n";
                    return;
                }
            } else {
                if (a[i] <= a[i + 1]) {
                    out << "NO\n";
                    return;
                }
            }
        }
        out << "YES\n";
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
