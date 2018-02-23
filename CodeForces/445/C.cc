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
        vector<int> t(n + 1);
        for (int i = 1; i <= n; ++i)
            in >> t[i];
        set<int> s{0};
        int res = 1;
        for (int i = 1; i <= n; ++i) {
            if (s.find(t[i]) != s.end()) {
                s.erase(t[i]);
                s.insert(i);
            } else {
                s.insert(i);
                ++res;
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
