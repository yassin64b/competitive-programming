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
        int n, m, k;
        in >> n >> m >> k;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            in >> v[i];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> fr(m, 0);
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == '.') {
                    fr[j] = 1 + (j > 0 ? fr[j - 1] : 0);
                } else {
                    fr[j] = 0;
                }
                if (fr[j] >= k) {
                    ++res;
                }
            }
        }
        if (k > 1) {
            for (int j = 0; j < m; ++j) {
                vector<int> fr(n, 0);
                for (int i = 0; i < n; ++i) {
                    if (v[i][j] == '.') {
                        fr[i] = 1 + (i > 0 ? fr[i - 1] : 0);
                    } else {
                        fr[i] = 0;
                    }
                    if (fr[i] >= k) {
                        ++res;
                    }
                }
            }
        }
        out << res << "\n";
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
