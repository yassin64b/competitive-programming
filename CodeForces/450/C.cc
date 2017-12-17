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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i)
            in >> p[i];
        
        vector<int> res(n + 1, 0);
        int lastmx = 0, curmx = 0;
        int ind = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] > curmx) {
                lastmx = curmx;
                curmx = p[i];
            } else {
                if (!ind) ind = p[i];
                ind = min(ind, p[i]);
                if (p[i] > lastmx) {
                    ++res[curmx];
                    lastmx = p[i];
                }
            }
        }
        ind = max(ind, 1);
        for (int i = 1; i <= n; ++i)
            if (res[i] > res[ind]) ind = i;
        if (res[ind] == 1) {
            if (p[0] == 1)
                out << 2 << "\n";
            else
                out << 1 << "\n";
        } else {
            out << ind << "\n";
        }
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