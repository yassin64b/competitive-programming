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

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> L(n);
        for (int i = 0; i < n; ++i)
            in >> L[i];
        int killUntil = n, sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i < killUntil)
                ++sum;
            killUntil = min(killUntil, i - L[i]);
        }
        out << sum << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
